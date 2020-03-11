#include <iostream>
#include "TMath.h"
using namespace std;

void TM(){
  Double_t lamb;
  Double_t A;
  const Double_t pi = TMath::Pi();
  
  TF1 *tm = new TF1("tm","[0]*2*pi*x*exp(-x/[1])",0,1000);

  std::cout << "Valor de lambida" << endl;
  std::cin >> lamb;
  std::cout << "Valor de A" << endl;
  std::cin >> A;
  
  tm->SetParameter(0,A);
  tm->SetParameter(1,lamb);
  TH1F *h = new TH1F("h","Hist Disnt de mt",100,0,1000);
  h->FillRandom("tm",10000);
  h->SetTitle("Distribuicao de massa tranversal (mt)");
  h->GetXaxis()->SetTitle("mt");
  h->GetYaxis()->SetTitle("DN/dmt");
  h->Draw();
}
