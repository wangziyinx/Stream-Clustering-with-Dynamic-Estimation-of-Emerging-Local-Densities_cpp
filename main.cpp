//
//  main.cpp
//  Clustering001
//
//  Created by Wang Ziyin on 5/28/18.
//  Copyright © 2018 Wang Ziyin. All rights reserved.
//

#include <iostream>
#include "Emerging_Density.hpp"
#include "Myfunctions.hpp"

using namespace std;
using namespace ED;

int main(int argc, const char * argv[]) {
    
    DTT_parameters parameter;
    
    
    parameter.pf=0.2;
    parameter.sim_thrsh=5000;
    parameter.compute_parameters();
    
    Dictionary Dic(parameter);
    Temperate_Table Table(parameter);
    

    string file_name = "data.txt";
    
    ifstream data_points;
    data_points.open(file_name);
    
    int dim = 0;
    string line;
    
    while (getline(data_points,  line)) {
        //        cout<<line<<endl;
        vector<string> string_segs=string_split(line," ");
        if (string_segs.size()<1) {
            break;
        }
        dim=(int)string_segs.size();
        double * p= new double[dim];
        
        for (int i=0; i<string_segs.size(); i++) {
            p[i]=stod(string_segs[i]);
        }
        process_one_point(Dic, Table, p);
    }
    data_points.close();
    
    cout<<"done"<<endl;
    
    string output="centers.txt";
    
    Dic.Dic_write(output);
    
    
    
    return 0;
}
