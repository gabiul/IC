#include <iostream>
#include "TMath.h"

void Gauss(){
  const Double_t sqrt2 = TMath::Sqrt(2*TMath::Pi());
  Double_t s;
  Double_t mean;
  
  std::cout << "Valor da média" << endl;
  std::cin >> mean;
  std::cout << "valor da energia de colisão" << endl;
  std::cin >> s;

  Double_t mp = 1.6726219;
  Double_t sigma = TMath::Sqrt(TMath::Log(TMath::Sqrt(s)/2*mp));
 
  TF1 *gau = new TF1("gau","1/([0]*sqrt2)*exp(-0.5*((x-[1])/[0])*((x-[1])/[0]))",-10,10); 
  gau->SetParameter(0,sigma);
  gau->SetParameter(1,mean);

  
  TH1F *h = new TH1F("h","Hist Dist de y",100,0,6);
  h->FillRandom("gau",10000);
  h->SetTitle("Distribuicao da rapidez");
  h->GetXaxis()->SetTitle("y");
  h->GetYaxis()->SetTitle("dN/dy");
  h->Draw();
}
