//
//  Emerging_Density.hpp
//  Clustering001
//
//  Created by Wang Ziyin on 5/28/18.
//  Copyright © 2018 Wang Ziyin. All rights reserved.
//

#ifndef Emerging_Density_hpp
#define Emerging_Density_hpp


#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <chrono>
#include <random>

#include "Myfunctions.hpp"

using namespace std;

namespace ED { // MT implements the Memory Tree clustering algorithm. It is the basic algorithm. It is the flat version though called "tree"
    class DTT_parameters{
    public:
        double sim_thrsh;
        double belta;
        double Fy;
        double pf;
        
        int dim;
        
        double sim_thrsh_low;
        int max_layer;
        double divide_factor;
        
        int init_val;
        double upper_thrsh;
        double sim_thrsh_density;
        
        DTT_parameters(){
            belta=0.01;
            Fy=2.23;
        }
        
        void compute_parameters(){
            init_val=(int) (log(belta)/log(1-pf)+1);
            upper_thrsh=(init_val*pf+Fy*sqrt(init_val*pf*(1-pf)))*init_val;
        }
        void compute_divide_factor(){
            double a=sim_thrsh/sim_thrsh_low;
            divide_factor=pow(a,1/((double)(max_layer-1)));
        }
    };
    
    
    
    
    class Dic_member{
    public:
        double * value;
        int num_member;
        
    };
    
    class Table_member{
    public:
        double * value;
        int num_member;
        int active_value;
        
    };
    
    
    class Dictionary{
    public:
        vector<Dic_member> centers;
        
        int dim;
        double sim_thrsh;
        
        int match(double * value);  //returns the index of matched entry (if success), returns a nagative integer if there is no match. The index starts from 0.
        void update(int indx, double * p);
        void Dic_write(string filename);
        void   Assign(vector<int> &A, vector<double *> &D);
        Dictionary(DTT_parameters &Parameters);
    };
    
    
    class Temperate_Table{
    public:
        vector<Table_member> centers;
        double sim_thrsh;
        int int_val;
        double upper_thresh;
        int dim;
        int match(double * value);
        void update(int indx, double * p, Dictionary &Dic); // indx is the return value of match(), it indicates which entry has been matched, -1 if no such mathc
        void decrease();
        Temperate_Table(DTT_parameters Parameters);
    };
    
    class Node{
    public:
        double * value;
        int ID;
        int vist;
    };
    
    void DTT_clustering (ED::Dictionary &Dic, ED::DTT_parameters &Parameters, vector <double *> &D );
    void process_one_point(ED::Dictionary &Dic, ED::Temperate_Table &Table, double *p);
}


#endif /* Emerging_Density_hpp */
