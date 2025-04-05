#include "resale_prediction.h"
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <time.h>

#define K 3              // Number of clusters
#define MAX_ITER 100     // Maximum iterations for convergence
#define TOLERANCE 0.001f // Convergence tolerance

// Helper function: absolute difference
static float absDiff(float a, float b) {
    return (a > b) ? (a - b) : (b - a);
}

// Helper function: compute mean of a set of floats
static float computeMean(float data[], int count) {
    if(count == 0) return 0.0f;
    float sum = 0.0f;
    for (int i = 0; i < count; i++) {
        sum += data[i];
    }
    return sum / count;
}

// K-means clustering on 1D data (historical resale factors)
// data: array of float values, n: number of data points, centroids: output array of length K.
static void kMeansClustering(float data[], int n, float centroids[K]) {
    // Initialize centroids by selecting K random points from data
    srand((unsigned int) time(NULL));
    for (int i = 0; i < K; i++) {
        int index = rand() % n;
        centroids[i] = data[index];
    }
    
    int assignments[n]; // Cluster assignment for each data point

    for (int iter = 0; iter < MAX_ITER; iter++) {
        // Assignment step
        for (int i = 0; i < n; i++) {
            float minDist = INFINITY;
            int bestCluster = 0;
            for (int j = 0; j < K; j++) {
                float dist = fabs(data[i] - centroids[j]);
                if (dist < minDist) {
                    minDist = dist;
                    bestCluster = j;
                }
            }
            assignments[i] = bestCluster;
        }
        
        // Update step: recalc centroids
        float newCentroids[K] = {0.0f};
        int counts[K] = {0};
        for (int i = 0; i < n; i++) {
            int cluster = assignments[i];
            newCentroids[cluster] += data[i];
            counts[cluster]++;
        }
        
        int converged = 1;
        for (int j = 0; j < K; j++) {
            if (counts[j] > 0) {
                newCentroids[j] /= counts[j];
            }
            if (fabs(newCentroids[j] - centroids[j]) > TOLERANCE) {
                converged = 0;
            }
            centroids[j] = newCentroids[j];
        }
        if (converged) break;
    }
}

// Given a new condition score, find the nearest centroid
static float predictResaleFactorFromCentroids(float conditionScore, float centroids[K]) {
    float minDiff = INFINITY;
    int bestIndex = 0;
    for (int j = 0; j < K; j++) {
        float diff = fabs(conditionScore - centroids[j]);
        if (diff < minDiff) {
            minDiff = diff;
            bestIndex = j;
        }
    }
    return centroids[bestIndex];
}

// Main function: Predict resale price using K-means clustering on historical resale factors.
float predictResalePriceKMeans(float originalPrice, float conditionScore) {
    // Historical resale factors (resalePrice/originalPrice ratios) from past products.
    float historicalData[] = {
        0.95f, 0.92f, 0.90f, 0.88f,  // High quality / New products
        0.80f, 0.78f, 0.75f, 0.77f,  // Refurbished products
        0.60f, 0.62f, 0.58f, 0.65f,  // Customer Remorse / Slightly used
        0.50f, 0.52f, 0.48f, 0.55f,  // Damaged products
        0.70f, 0.68f, 0.72f, 0.69f   // Average quality products
    };
    int n = sizeof(historicalData) / sizeof(historicalData[0]);
    
    float centroids[K];
    // Run K-means clustering on the historical data.
    kMeansClustering(historicalData, n, centroids);
    
    // For debugging, you might print the centroids:
    // printf("Cluster centroids: ");
    // for (int j = 0; j < K; j++) { printf("%.2f ", centroids[j]); }
    // printf("\n");
    
    // Use the input conditionScore to determine the predicted resale factor.
    float predictedFactor = predictResaleFactorFromCentroids(conditionScore, centroids);
    
    // Calculate and return the predicted resale price.
    float predictedResalePrice = originalPrice * predictedFactor;
    return predictedResalePrice;
}

