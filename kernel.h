#pragma once

double** get_gaussian_kernel(pair<int,int> p, double sigma, int M, int N){
    int y=p.first;
    int x=p.second;
    double div=2*sigma*sigma;

    double sum=0; // for normalization

    double **kernel= new double*[M];

    for (int i = 0; i < M; ++i) {
        kernel[i]=new double[N];
        for (int j = 0; j < N; ++j) {
            //shift to the point {y,x}
            double num=(i-y)*(i-y)+(j-x)*(j-x);
            kernel[i][j]=exp(-num/div)/(div*M_PI);
            sum+=kernel[i][j];
        }
    }

    for (int i = 0; i < M; ++i) {
        for (int j = 0; j < N; ++j) {
            kernel[i][j]/=sum;
        }
    }
            return kernel;
}

void print_kernel(double** kernel, int M, int N){
    for (int i = 0; i < M; ++i) {
        for (int j = 0; j < N; ++j) {
            printf("%.2f", kernel[i][j]);
            cout<<" ";
        }
        cout<<endl;
    }
}