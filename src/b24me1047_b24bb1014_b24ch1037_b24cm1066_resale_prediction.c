#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>
#include"b24me1047_b24bb1014_b24ch1037_b24cm1066_resale_prediction.h"

#define K 3 
#define MAX_ITER 100  
#define TOLERANCE 0.001  

float absDiff (float a, float b){

    return (a > b) ? (a - b) : (b - a);
}

void kMeansClustering (float data[], int n, float centroids[K]){

    srand ((unsigned int) time (NULL)); // Random Number Generation (centroids)

    for (int i = 0; i < K; i++){
        int index = rand () % n; // %n - ensures the random number is within the range of 0 - (n-1)
        centroids[i] = data[index]; // 3 random numbers are choosen and declared to be centroids 
    }

    int assignments[n];

    // The code given below goes to each data point , calculates its distance from all the 3 centroids
    // and then stores the cluster number in assignments array (one with min Dist is stored) 

    for (int iter = 0; iter < MAX_ITER; iter++){
        for (int i = 0; i < n; i++){
            float minDist = INFINITY;
            int bestCluster = 0;

            for (int j = 0; j < K; j++){

                float dist = absDiff(data[i],centroids[j]);
                if (dist < minDist){
                    minDist = dist;
                    bestCluster = j;
                }
            }

            assignments[i] = bestCluster;
        }

        float newCentroids[K] = {0};
        int counts[K] = {0};
        int cluster;

// Calculating new centroids by taking the means of respective clusters

        for (int i = 0; i < n; i++){
            cluster = assignments[i];
            newCentroids[cluster] += data[i];
            counts[cluster]++;
        }

        int converged = 1;

// Assign new Centroids the value of means and check if the diff > TOLERANCE

        for (int j = 0; j < K; j++){

            if (counts[j] > 0){
                newCentroids[j] = newCentroids[j] / counts[j];
            }

            if (absDiff (centroids[j] , newCentroids[j]) > TOLERANCE){
                converged = 0;
            }
            centroids[j] = newCentroids[j];
        }

        if (converged){
            break;
        }

    }

}

// Calculate best index means closest cluster based on new conditionScore given by user

float predictResaleFactorFromCentroids(float conditionScore, float centroids[K]){

    float minDiff = INFINITY;
    int bestIndex = 0;

    for (int j = 0; j < K; j++){

        float diff = absDiff (conditionScore, centroids[j]);

        if (diff < minDiff){
            minDiff = diff;
            bestIndex = j;
        }
    }

    return centroids[bestIndex];

}

float predictResalePriceKMeans(float originalPrice, float conditionScore) {

    float historicalData [] = {
        0.95f, 0.92f, 0.90f, 0.88f,  // High quality
        0.80f, 0.78f, 0.75f, 0.77f,  // Refurbished products
        0.60f, 0.62f, 0.58f, 0.65f,  // Mid Quality
        0.50f, 0.52f, 0.48f, 0.55f,  // Damaged products
        0.70f, 0.68f, 0.72f, 0.69f   // Average quality products
    };

    int n = sizeof(historicalData) / sizeof(historicalData[0]);

    float centroids[K];

    kMeansClustering(historicalData, n, centroids);

    float predictedFactor = predictResaleFactorFromCentroids(conditionScore, centroids);
    
    float predictedResalePrice = originalPrice * predictedFactor;

    return predictedResalePrice;

}



