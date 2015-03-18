void vectorData(std::vector<float> &v){
  TFile *f  = new TFile("datafile_ex1.root","READ");
  f -> cd();
  

  TNtuple *ntuple = NULL;
  f -> GetObject("data",ntuple);
  



  for(unsigned int i =0; i<ntuple -> GetEntries(); ++i){
    float x_;
    ntuple -> SetBranchAddress("x", &x_);

    ntuple -> GetEntry(i);
    v.push_back(x_);
    
  }
}
