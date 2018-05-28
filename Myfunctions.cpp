//
//  Myfunctions.cpp
//  Clustering001
//
//  Created by Wang Ziyin on 5/28/18.
//  Copyright © 2018 Wang Ziyin. All rights reserved.
//

#include "Myfunctions.hpp"




double similarity_measure(double *x, double *y, string opt, int dim){
    if (opt.compare("euclidean")==0) {
        double s=0;
        for (int  i=0; i<dim; i++) {
            s+=(x[i]-y[i])*(x[i]-y[i]);
        }
        s=sqrt(s);
        return -s;
    }
    else if (opt.compare("cosine")==0) {
        double s=cosine_similarity(x, y, dim);
        return s;
    }
    else {
        cout<<"no such option"<<endl;
        return -1;
    }
}

double cosine_similarity(double *a, double *b, int dim){
    
    double sum1=0;
    double sum_a=0;
    double sum_b=0;
    
    for (int i=0; i<dim; i++) {
        sum1+=a[i]*b[i];
        sum_a+=a[i]*a[i];
        sum_b+=b[i]*b[i];
    }
    return sum1/(sqrt((double)sum_a)*sqrt(sum_b));
}




void histogram (vector <int > &A, vector<double> &H , int max_bin){
    
    for ( int i=0; i<max_bin; i++)
        H.push_back(0);
    for (int i=0; i<A.size(); i++)
        H[A[i]] +=1;
    
    
    
    double norm_sum = 0;
    for (int i =0; i<H.size(); i++)
        norm_sum+=H[i] * H[i];
    norm_sum=sqrt(norm_sum);
    for (int i =0; i<H.size(); i++)
        H[i] /=norm_sum;
}


int vec_min(vector<double > A){
    double m = INFINITY;
    int Indx =0;
    for (int i =0; i<A.size(); i++) {
        if (A[i]<m) {
            m = A[i];
            Indx = i;
        }
    }
    return Indx;
}


int vec_max(vector<double > A){
    double m = -INFINITY;
    int Indx =0;
    for (int i =0; i<A.size(); i++) {
        if (A[i]>m) {
            m = A[i];
            Indx = i;
        }
    }
    return Indx;
}
int read_data(string file_name, vector<double *> &Data){
    
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
        double * this_point= new double[string_segs.size()];
        
        dim=(int)string_segs.size();
        for (int i=0; i<string_segs.size(); i++) {
            this_point[i]=stod(string_segs[i]);
        }
        Data.push_back(this_point);
    }
    
    data_points.close();
    return dim;
}


vector<string> string_split(string a, string del){
    char *p=new char[a.size()+1];
    char *d=new char[del.size()+1];
    
    //    char *del=new char[del_str.size()+1];
    int i=0;
    //    int number_of_item;
    vector<string> string_seg;
    
    strcpy(p,a.c_str());
    strcpy(d,del.c_str());
    //    number_of_item=number_of_char(a, del)+1;
    
    
    char *tokenPtr=strtok(p, d);
    while(tokenPtr!=NULL) {
        string_seg.push_back((string)tokenPtr);
        i++;
        tokenPtr=strtok(NULL, d);
    }
    return string_seg;
}


