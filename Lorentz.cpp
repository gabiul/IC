#include <iostream>

float gama(float beta){
  return pow(sqrt(1-pow(beta,2)),-1);
}

float transf(float r,float beta){

  float R = r/gama(beta);
  return R;
}

void Lorentz(){
  float r; // pm Au = 174
  std::cout << "ráio do átomo em [pm]" << endl;
  std::cin >> r;
  
  float c = 300; 
  float v;
  std::cout << "velocidade da partícula x*c" << endl;
  std::cin >> v;
  float beta = v;

  float R = transf(r,beta);

  TF3 *re = new TF3("re","(x/[0])*(x/[0])+(y/[1])*(y/[1])+(z/[2])*(z/[2])-1",-200,200,-200,200,-200,200);
  re->SetParameter(0,R);
  re->SetParameter(1,r);
  re->SetParameter(2,r);
  re->GetXaxis()->SetTitle("Z (pm)");
  re->GetXaxis()->SetTitleOffset(2);
  re->GetYaxis()->SetTitle("X (pm)");
  re->GetXaxis()->SetTitleOffset(2);
  re->GetZaxis()->SetTitle("Y(pm)");
  re->GetXaxis()->SetTitleOffset(2);
  re->SetTitle("Esfera relativistica");
  re->SetLineColor(kBlue);
  re->Draw();
  
}
