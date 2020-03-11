#include <iostream>
using namespace std;
// Colisão no ref da particula target

float gama(float beta){
  return pow(sqrt(1-pow(beta,2)),-1);
}

float vel(float v, float c){
  return (2*v)/(1+(v*v/(c*c)));
}

float transf(float d,float beta){

  float D = d/gama(beta);
  return D;
}

float coli2(){
  float c = TMath::C(); // [m]/[s]
  float v = 0.99*c;
  float beta = vel(v,c)/c;

  float dT; // [pm] Au = 348, Pb = ,etc
  float dP; // [pm]
  std::cout << "diametro do alvo em [pm]" << endl; 
  std::cin >> dT; 
  std::cout << "diametro do prejetil em [pm]" << endl;
  std::cin >> dP;

  float DP = transf(dP,beta);

  float tl = (dT+dP)*1e-12/vel(v,c);
  std::cout << tl << endl;
  std::cout << vel(v,c) << endl;
  return (dT+DP)*1e-12/vel(v,c); // [s]
}
