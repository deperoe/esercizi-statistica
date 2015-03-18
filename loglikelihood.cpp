#include <vector>
#include "TFile.h"
#include "TMath.h"
#include "TNtuple.h"  
#include "vectorData.cpp"

  float eval_NLL(std::vector<float> &v, float mu){
    float sigma = 1;
    float nll = 0;
    for(size_t i =0; i< v.size();++i)
      nll += TMath::Log(TMath::Gaus(v.at(i),mu,sigma));

    return -nll;
  }




  void loglikelihood() {
    
    std::vector<float> values;
    vectorData(values);
    unsigned int N = 10000;
    std::vector<float> linspacex;
    std::vector<float> linspacey;
    int a =0;
    int b=10;
    float dx = static_cast<float>(b-a)/N;
    for(unsigned int i =0; i < N; ++i){
      linspacex.push_back(a +i*dx);
      linspacey.push_back(eval_NLL(values,a +i*dx));}


    //for control purpose
    /*    for(unsigned int i =0; i < N; ++i)
      cout << linspacex[i] << "  ";
    cout << endl; 
    for(unsigned int i =0; i < N; ++i)
      cout << linspacey[i] << "  ";
      cout << endl;*/  

    TGraph *g = new TGraph(N,&linspacex[0],&linspacey[0]);
    g -> SetMarkerColor(kRed);
    g-> SetLineWidth(5);
    g -> SetTitle("Maximum likelihood");
    g -> GetXaxis()-> SetRangeUser(0,10);
    g -> Draw("AC");    //with the C Option a smooth curve is drawn
    int miny = TMath::LocMin(N,g ->GetY());     //localize the minimum of the array and gives back its position
    cout << "minimum of the function is in:   " << linspacex[miny] << endl;
  }
    

