
void random_gauss(matrix<double> &J, int N)
{
   double sigma=0.3,mu=0,rx,ru; 
   double rt,rs,rho,theta,pi=acos(-1.0);
      //Seed for random number generator.
   srand(0);

   for (int i=0;i<N;i++){
      for (int j=0;j<N;j++){


      //Generation of random number.
          ru = double(rand())/RAND_MAX;
          rt = - log(1.0 - ru);
          ru = double(rand())/RAND_MAX;
          rs = ru;
          rho = sigma * sqrt(2 * rt);
          theta = 2 * pi * rs;
          rx = rho * cos(theta) + mu;
          J(i,j)=rx;
      }
   }
}

