//
//  Myfunctions.hpp
//  Clustering001
//
//  Created by Wang Ziyin on 5/28/18.
//  Copyright © 2018 Wang Ziyin. All rights reserved.
//

#ifndef Myfunctions_hpp
#define Myfunctions_hpp

#include <stdio.h>
#include <vector>
#include <iostream>
#include <fstream>
#include <string>
#include <math.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <ctime>



using namespace std;

double similarity_measure(double *x, double *y, string opt, int dim);
double cosine_similarity(double *a, double *b, int dim);
void histogram (vector <int > &A, vector<double> &H , int max_bin);

int vec_min(vector<double > A);
int vec_max(vector<double > A);


int read_data(string file_name, vector<double *> &Data);
vector<string> string_split(string a, string del);


#endif /* Myfunctions_hpp */
