#ifndef MATCHING_H
#define MATCHING_H

#include <vector>
#include "cutils.h"
#include "cuSIFT.h"

using namespace std;

typedef enum {
  MatchSiftDistanceDotProduct,
  MatchSiftDistanceL2
} MatchSiftDistance;

typedef struct {
  // Pointers to SiftPoint data
  SiftPoint *pt1;
  SiftPoint *pt2;

  // Match statistics
  float score;      // Distance metric (e.g., dot product or L2 distance)
  float ambiguity;  // Ratio of 2nd best and best match
  float error;
} SiftMatch;

// Perform an exhaustive search between all sift key points between two images
vector<SiftMatch *> MatchSiftData(SiftData &data1,
                                  SiftData &data2,
                                  MatchSiftDistance distance = MatchSiftDistanceL2,
                                  float scoreThreshold = 0.3,
                                  float ambiguityThreshold = 0.36);

#endif