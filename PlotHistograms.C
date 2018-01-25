//Format 1D histograms
//Just plot colours
void setup1Dhist(TH1* hist, Int_t colour){
    hist->SetMarkerStyle(21);
    hist->SetMarkerSize(0.8);
    hist->SetMarkerColor(colour);
    hist->SetLineColor(colour);
}
//Add titles
void setup1Dhist(TH1* hist, Int_t colour, TString xAxis, TString yAxis){
    hist->SetMarkerStyle(21);
    hist->SetMarkerSize(0.8);
    hist->SetMarkerColor(colour);
    hist->SetLineColor(colour);
    hist->GetYaxis()->SetTitle(yAxis);
    hist->GetXaxis()->SetTitle(xAxis);
}

void setup1Dgraph(TGraph *gr, Int_t colour, TString xAxis, TString yAxis){
    gr->SetMarkerStyle(19);
    gr->SetMarkerSize(1.2);
    gr->SetMarkerColor(colour);
    gr->SetLineColor(colour);
    gr->GetYaxis()->SetTitle(yAxis);
    gr->GetXaxis()->SetTitle(xAxis);
}

void setup1Dgraph(TGraph *gr, Int_t colour){
    gr->SetMarkerStyle(19);
    gr->SetMarkerSize(1.2);
    gr->SetMarkerColor(colour);
    gr->SetLineColor(colour);
}

void setup2Dhist(TH2* hist, Int_t colour, TString xAxis, TString yAxis){
    hist->SetMarkerStyle(21);
    hist->SetMarkerColor(colour);
    hist->SetLineColor(colour);
    hist->GetYaxis()->SetTitle(yAxis);
    hist->GetXaxis()->SetTitle(xAxis);
}

//Enforce ALICE formatting
void SetStyle() {
    //gStyle->Reset("Plain");
    gStyle->SetOptTitle(0); // no title
    gStyle->SetOptStat(0);
    gStyle->SetPalette(56); //54
    gStyle->SetCanvasColor(10);
    gStyle->SetCanvasBorderMode(0);
    gStyle->SetFrameLineWidth(1);
    gStyle->SetFrameFillColor(kWhite);
    gStyle->SetPadColor(10);
    gStyle->SetPadTickX(1);
    gStyle->SetPadTickY(1);
    gStyle->SetPadBottomMargin(0.15);
    gStyle->SetPadLeftMargin(0.15);
    gStyle->SetHistLineWidth(1);
    gStyle->SetHistLineColor(kRed);
    gStyle->SetFuncWidth(2);
    gStyle->SetFuncColor(kGreen);
    gStyle->SetLineWidth(2);
    gStyle->SetLabelSize(0.045,"xyz");
    gStyle->SetLabelOffset(0.01,"y");
    gStyle->SetLabelOffset(0.01,"x");
    gStyle->SetLabelColor(kBlack,"xyz");
    gStyle->SetTitleSize(0.05,"xyz");
    gStyle->SetTitleOffset(1.4,"y");
    gStyle->SetTitleOffset(1.2,"x");
    gStyle->SetTitleFillColor(kWhite);
    gStyle->SetTextSizePixels(26);
    gStyle->SetTextFont(42);
    //  gStyle->SetTickLength(0.04,"X");  gStyle->SetTickLength(0.04,"Y"); 

    gStyle->SetLegendBorderSize(0);
    gStyle->SetLegendFillColor(kWhite);
    //  gStyle->SetFillColor(kWhite);
    gStyle->SetLegendFont(42);

    std::cout << "VIP2 style set!" << std::endl;


}

Double_t landauFunction( Double_t *x, Double_t *par ) 
{ 
   // 0  ..mu
    //        1... scale par
    // 2 gain
    Double_t xx = x[0];
    Double_t cosmicHitFunc = TMath::Landau( xx, par[0], par[1], 0 ) * par[2] ;

    return cosmicHitFunc; 
}


void PlotHistograms(Int_t colour1, Int_t colour2, Int_t width, Int_t height){
    
    // .x PlotHistograms.C(4,2,800,600)
    // without a version number of the histogram, root takes the latest one
    SetStyle();
    gROOT->SetBatch(kTRUE); // suppress output
    gROOT->ForceStyle();  // force the current style onto everything
    
    TFile *f = new TFile("/home/andreas/vip2/thesis/Latex/Figures/root/Histograms_4.root","READ");
    //f->ls();
    
    // ---------------------        chapter 4 ---------------------------
    
//    TCanvas *c1 = new TCanvas("c1", "c1", width, height);
//    TH1F *h1 = (TH1F*)f->Get("ht1");
//    h1->GetXaxis()->SetRangeUser(2.,20.);
//    setup1Dhist(h1,colour1,"Energy [MeV]","");
//    //gPad->SetLogy();
//    h1->Draw();
//    c1->Print("/home/andreas/vip2/thesis/Latex/Figures/root/Plots/muonEnDep.pdf");
//    
//    
//    TCanvas *c2 = new TCanvas("c2", "c2", width, height);
//    TH1F *h2 = (TH1F*)f->Get("ht4"); // single spectrum red ... originally 100 eV binning
//    h2->Rebin(2.);
//    h2->GetXaxis()->SetRangeUser(0.,80.);
//    TH1F *h3 = (TH1F*)f->Get("ht5"); // with veto blue ... originally 200 eV binning
//    setup1Dhist(h2,colour2,"Energy [keV]","Counts #/ 200 eV");
//    setup1Dhist(h3,colour1);
//    h2->Draw();
//    h3->Draw("same");
//    
//    c2->Print("/home/andreas/vip2/thesis/Latex/Figures/root/Plots/cosmicRej.pdf");
//    
//    
//    TCanvas *c3 = new TCanvas("c3", "c3", width, height);
//    TH1F *h4 = (TH1F*)f->Get("hSddEdepCosm"); // single spectrum
//    //h4->Rebin(10.);
//    setup1Dhist(h4,colour1,"Energy [keV]","Counts #/ 10 keV");
//    h4->Draw();
//    
//    c3->Print("/home/andreas/vip2/thesis/Latex/Figures/root/Plots/sddEnFromCos.pdf");
//    
//    
//    TCanvas *c4 = new TCanvas("c4", "c4", width, height);
//    TH1F *h5 = (TH1F*)f->Get("hGammaEneDep"); // single spectrum red ... originally 1 kev binning
//    //h5->Rebin(2.);
//    //h2->GetXaxis()->SetRangeUser(0.,80.);
//    TH1F *h6 = (TH1F*)f->Get("hGammaEneDepVeto"); // with veto blue
//    setup1Dhist(h5,colour2,"Energy [keV]","Counts #/ 1 keV");
//    setup1Dhist(h6,colour1);
//    gPad->SetLogy();
//    h5->Draw();
//    h6->Draw("same");
//    
//    c4->Print("/home/andreas/vip2/thesis/Latex/Figures/root/Plots/gammaRej.pdf");
//    
//    
//    TCanvas *c5 = new TCanvas("c5", "c5", width, height);
//    TH1F *h7 = (TH1F*)f->Get("hGammaEnDepLowEn"); // single spectrum ...originally 10 eV binning 
//    h7->Rebin(10.);
//    setup1Dhist(h7,colour1,"Energy [keV]","Counts #/ 100 eV");
//    gPad->SetLogy();
//    h7->Draw();
//    
//    c5->Print("/home/andreas/vip2/thesis/Latex/Figures/root/Plots/sddEnFromGamma.pdf");
    
    
    
    // --------------------------------   chapter 5 -------------------------------------------------
    
    TFile *g = new TFile("/home/andreas/vip2/thesis/Latex/Figures/root/Histograms_5.root","READ");
    g->ls();
    
    TCanvas *c6 = new TCanvas("c6", "c6", width, height);
    TH1F *h8 = (TH1F*)g->Get("hTarget1TempNoCool");
    TH1F *h9 = (TH1F*)g->Get("hTarget2TempNoCool");
    //h1->GetXaxis()->SetRangeUser(2.,20.);
    //setup1Dhist(h1,colour1,"Energy [MeV]","");
    //gPad->SetLogy();
    h8->GetXaxis()->SetTimeDisplay(1);
    h9->GetXaxis()->SetTimeDisplay(1);
    h8->GetXaxis()->SetTimeFormat("%H:%M");
    h9->GetXaxis()->SetTimeFormat("%H:%M");
    setup1Dhist(h8,colour1,"Time [h]","Temperature [#circC]");
    setup1Dhist(h9,colour2);
    //h->GetXaxis()->SetTimeFormat("%d\/%m\/%y%F2000-02-28 13:00:01");
    h8->Draw();
    h9->Draw("same");
    c6->Print("/home/andreas/vip2/thesis/Latex/Figures/root/Plots/targetTempNoCooling.pdf");
    
    TCanvas *c7 = new TCanvas("c7", "c7", width, height);
    TH1F *h10 = (TH1F*)g->Get("hTarget1TempWithCool");
    TH1F *h11 = (TH1F*)g->Get("hTarget2TempWithCool");
    //h1->GetXaxis()->SetRangeUser(2.,20.);
    //setup1Dhist(h1,colour1,"Energy [MeV]","");
    //gPad->SetLogy();
    h10->GetXaxis()->SetTimeDisplay(1);
    h11->GetXaxis()->SetTimeDisplay(1);
    h10->GetXaxis()->SetTimeFormat("%H:%M");
    h11->GetXaxis()->SetTimeFormat("%H:%M");
    setup1Dhist(h10,colour1,"Time [h]","Temperature [#circC]");
    setup1Dhist(h11,colour2);
    //h->GetXaxis()->SetTimeFormat("%d\/%m\/%y%F2000-02-28 13:00:01");
    h10->Draw();
    h11->Draw("same");
    c7->Print("/home/andreas/vip2/thesis/Latex/Figures/root/Plots/targetTempWithCooling.pdf");
    
    TCanvas *c8 = new TCanvas("c8", "c8", width, height);
    TH1F *h12 = (TH1F*)g->Get("hSddEnSpecSmi");
    h12->Rebin(10);
    setup1Dhist(h12,colour1,"Energy [eV]","Counts #/10 eV");
    h12->GetXaxis()->SetRangeUser(1000,10000);
    gPad->SetLogy();
    h12->Draw();
    c8->Print("/home/andreas/vip2/thesis/Latex/Figures/root/Plots/sumEnSpecSmi.pdf");
    
    TCanvas *c9 = new TCanvas("c9", "c9", width, height);
    TH1F *h13 = (TH1F*)g->Get("hCs133VSpec");
    h13->GetXaxis()->SetRangeUser(0.05,0.3);
    h13->GetYaxis()->SetRangeUser(0.,215.);
    setup1Dhist(h13,colour1,"Voltage [V]","Counts [a.u.]");
    //gPad->SetLogy();
    h13->Draw();
    c9->Print("/home/andreas/vip2/thesis/Latex/Figures/root/Plots/Cs133VSpec.pdf");
    
    TCanvas *c10 = new TCanvas("c10", "c10", width, height);
    TGraph *h14 = (TGraph*)g->Get("gCs133MCSpectra");
    //h14->GetXaxis()->SetTitle("Energy [keV]");
    //h14->GetYaxis()->SetTitle("Counts");
    setup1Dgraph(h14,colour1,"Energy [keV]","Counts [a.u.]");
    //gPad->SetLogy();
    h14->Draw("AP");
    c10->Print("/home/andreas/vip2/thesis/Latex/Figures/root/Plots/Cs133ESpec.pdf");
    
    TCanvas *c11 = new TCanvas("c11", "c11", width, height);
    TH1F *h15 = (TH1F*)g->Get("hSddTimeRes");
    int nbins = h15->GetXaxis()->GetNbins();
    TH1F *hnew = new TH1F("hnew","title",nbins,0,900);
    for (int i=1;i<=nbins;i++){
      double y = h15->GetBinContent(i);
      double x = h15->GetXaxis()->GetBinCenter(i);
      double xnew = x * 0.1;  //from tdc channel to ns
      hnew->Fill(xnew,y);
    }
    setup1Dhist(hnew,colour1,"Time [ns]","Counts #/10 ns");
    hnew->Rebin(10.);
    //gPad->SetLogy();
    //TF1 *f1 = new TF1("f1","gaus(0)",50,500);
//    TF1 *f1 = new TF1("f1",landauFunction,0,900,3);
//    f1->SetParameters(250.,60.,1800.);
//    f1->SetParLimits(0,220.,350.);
//    f1->SetParLimits(1,60.,120.);
//    f1->SetParLimits(2,1500.,2500.);
    //hnew->Fit("f1","R");
    hnew->Draw("hist"); // draw without error bars
    //f1->Draw("same");
    c11->Print("/home/andreas/vip2/thesis/Latex/Figures/root/Plots/SddTimeRes.pdf");
    
    
    TCanvas *c12 = new TCanvas("c12", "c12", width, height);
    TH1F *h16 = (TH1F*)g->Get("hScintiTimeRes");
    int nbins2 = h16->GetXaxis()->GetNbins();
    TH1F *hnew2 = new TH1F("hnew2","title",nbins2,-20,20);
    for (int i=1;i<=nbins2;i++){
      double y = h16->GetBinContent(i);
      double x = h16->GetXaxis()->GetBinCenter(i);
      double xnew = x * 0.1 + 3.348;  //from tdc channel to ns
      hnew2->Fill(xnew,y);
    }
    setup1Dhist(hnew2,colour1,"Time [ns]","Counts #/100 ps");
    //hnew2->Rebin(10.);
    //gPad->SetLogy();
    //TF1 *f2 = new TF1("f2","gaus(0)",-100,50);
//    TF1 *f1 = new TF1("f1",landauFunction,0,900,3);
//    f1->SetParameters(250.,60.,1800.);
//    f1->SetParLimits(0,220.,350.);
//    f1->SetParLimits(1,60.,120.);
//    f1->SetParLimits(2,1500.,2500.);
    //h16->Fit("f2","RI");
    hnew2->GetXaxis()->SetRangeUser(-10,10);
    hnew2->Draw("hist"); // draw without error bars
   // f2->Draw("same");
    c12->Print("/home/andreas/vip2/thesis/Latex/Figures/root/Plots/ScintiTimeRes.pdf");
    
    TCanvas *c13 = new TCanvas("c13", "c13", width, height);
    TH2F *h17 = (TH2F*)g->Get("hTdcSumCounts");
    //h14->GetXaxis()->SetTitle("Energy [keV]");
    //h14->GetYaxis()->SetTitle("Counts");
    setup2Dhist(h17,colour1,"Column","Layer");
    //gPad->SetLogy();
    h17->Draw("box,text");
    c13->Print("/home/andreas/vip2/thesis/Latex/Figures/root/Plots/tdcSumCounts.pdf");
    
    TCanvas *c14 = new TCanvas("c14", "c14", width, height);
    TH2F *h18 = (TH2F*)g->Get("qdcSumCounts");
    //h14->GetXaxis()->SetTitle("Energy [keV]");
    //h14->GetYaxis()->SetTitle("Counts");
    setup2Dhist(h18,colour1,"Column","Layer");
    //gPad->SetLogy();
    h18->Draw("box,text");
    c14->Print("/home/andreas/vip2/thesis/Latex/Figures/root/Plots/qdcSumCounts.pdf");
    
    TCanvas *c15 = new TCanvas("c15", "c15", width, height);
    TH2F *h19 = (TH2F*)g->Get("hQdc22HitPattern");
    //h14->GetXaxis()->SetTitle("Energy [keV]");
    //h14->GetYaxis()->SetTitle("Counts");
    setup2Dhist(h19,colour1,"Column","Layer");
    //gPad->SetLogy();
    h19->Draw("box,text");
    c15->Print("/home/andreas/vip2/thesis/Latex/Figures/root/Plots/qdc22HitPattern.pdf");
    
    TCanvas *c16 = new TCanvas("c16", "c16", width, height);
    TH1F *h20 = (TH1F*)g->Get("hQdc5Spec");
    h20->GetXaxis()->SetRangeUser(150,4200);
    //h14->GetYaxis()->SetTitle("Counts");
    setup1Dhist(h20,colour1,"QDC Channel","Counts #/ Ch");
    gPad->SetLogy();
    h20->Draw();
    c16->Print("/home/andreas/vip2/thesis/Latex/Figures/root/Plots/qdc5SpectrumLog.pdf");
    
    TCanvas *c17 = new TCanvas("c17", "c17", width, height);
    TH1F *h21 = (TH1F*)g->Get("hQdc5Spec");
    //h14->GetXaxis()->SetTitle("Energy [keV]");
    h21->GetXaxis()->SetRangeUser(800,4200);
    setup1Dhist(h21,colour1,"QDC Channel","Counts #/ Ch");
    //gPad->SetLogy();
    h21->Draw();
    c17->Print("/home/andreas/vip2/thesis/Latex/Figures/root/Plots/qdc5SpectrumLinear.pdf");
    
    TCanvas *c18 = new TCanvas("c18", "c18", width, height);
    TH1F *h22 = (TH1F*)g->Get("hScintRejSmi");
    //h14->GetXaxis()->SetTitle("Energy [keV]");
    h22->Rebin(100.);
    h22->GetXaxis()->SetRangeUser(1000,40000);
    setup1Dhist(h22,colour1,"Energy [eV]","Counts #/ 100 eV");
    gPad->SetLogy();
    h22->Draw();
    c18->Print("/home/andreas/vip2/thesis/Latex/Figures/root/Plots/scintRejSmi.pdf");
    
    TCanvas *c19 = new TCanvas("c19", "c19", width, height);
    TH1F *h23 = (TH1F*)f->Get("ht4"); // single spectrum red ... originally 100 eV binning
    setup1Dhist(h23,colour1,"Energy [keV]","Counts #/ 100 eV");
    h23->GetXaxis()->SetRangeUser(0,40);
    //gPad->SetLogy();
    h23->Draw();
    c19->Print("/home/andreas/vip2/thesis/Latex/Figures/root/Plots/cosmicRej100eV.pdf");
    
    TCanvas *c20 = new TCanvas("c20", "c20", width, height);
    TH1F *h24 = (TH1F*)g->Get("hSddEnSpecSmi"); // 1 eV binning
    h24->Rebin(100);
    setup1Dhist(h24,colour2,"Energy [eV]","Counts #/100 eV");
    h24->GetYaxis()->SetRangeUser(1.,200000.);
    h24->GetXaxis()->SetRangeUser(3000.,40000.);
    gPad->SetLogy();
    h24->Draw();
    h22->Draw("same");
    c20->Print("/home/andreas/vip2/thesis/Latex/Figures/root/Plots/rejCompSpectrumSmi.pdf");
    
    TCanvas *c21 = new TCanvas("c21", "c21", width, height);
    TGraph *h25 = (TGraph*)g->Get("gSdd1TempNew");
    TGraph *h26 = (TGraph*)g->Get("gSdd2TempNew");
    //gPad->SetLogy();
    h25->GetXaxis()->SetTimeDisplay(1);
    h26->GetXaxis()->SetTimeDisplay(1);
    h25->GetXaxis()->SetTimeFormat("%H:%M");
    h26->GetXaxis()->SetTimeFormat("%H:%M");
    h26->GetYaxis()->SetRangeUser(-173.,-151.);
    h26->GetXaxis()->SetRangeUser(1445637000.,1445725000.);
    h26->GetXaxis()->SetNdivisions(9); 
    setup1Dgraph(h26,colour1,"Time [h]","Temperature [#circC]");
    h25->SetMarkerSize(0.);
    setup1Dgraph(h25,colour2);
    h26->SetMarkerSize(0.);
    //h->GetXaxis()->SetTimeFormat("%d\/%m\/%y%F2000-02-28 13:00:01");
    h26->Draw();
    h25->Draw("same");
    c21->Print("/home/andreas/vip2/thesis/Latex/Figures/root/Plots/sddTemp.pdf");

    g->Close();
    f->Close();
    
}