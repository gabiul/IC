#include <iostream>
using namespace std;
// Colisão no ref do lab

float gama(float beta){
  return pow(sqrt(1-pow(beta,2)),-1);
}

float transf(float d,float beta){

  float D = d/gama(beta);
  return D;
}

float coli(){
  Double_t c = TMath::C(); // [m]/[mis]
  float v = 0.99*c;
  float beta = v/c;
   
  float dP; // [pm] Au = 348, Pb = ,etc
  std::cout << "diametro do prejetil em [pm]" << endl;
  std::cin >> dP;

  float DP = transf(dP,beta);

  float tl = (dP)*1e-12/v;
  std::cout << tl << endl;
  std::cout << v << endl;
  return DP*1e-12/v;
}

