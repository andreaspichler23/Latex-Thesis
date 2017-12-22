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
//    TH1F *h2 = (TH1F*)f->Get("ht4"); // single spectrum red
//    h2->Rebin(2.);
//    h2->GetXaxis()->SetRangeUser(0.,80.);
//    TH1F *h3 = (TH1F*)f->Get("ht5"); // with veto blue
//    setup1Dhist(h2,colour2,"Energy [keV]","");
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
//    setup1Dhist(h4,colour1,"Energy [keV]","");
//    h4->Draw();
//    
//    c3->Print("/home/andreas/vip2/thesis/Latex/Figures/root/Plots/sddEnFromCos.pdf");
//    
//    
//    TCanvas *c4 = new TCanvas("c4", "c4", width, height);
//    TH1F *h5 = (TH1F*)f->Get("hGammaEneDep"); // single spectrum red
//    //h5->Rebin(2.);
//    //h2->GetXaxis()->SetRangeUser(0.,80.);
//    TH1F *h6 = (TH1F*)f->Get("hGammaEneDepVeto"); // with veto blue
//    setup1Dhist(h5,colour2,"Energy [keV]","");
//    setup1Dhist(h6,colour1);
//    gPad->SetLogy();
//    h5->Draw();
//    h6->Draw("same");
//    
//    c4->Print("/home/andreas/vip2/thesis/Latex/Figures/root/Plots/gammaRej.pdf");
//    
//    
//    TCanvas *c5 = new TCanvas("c5", "c5", width, height);
//    TH1F *h7 = (TH1F*)f->Get("hGammaEnDepLowEn"); // single spectrum
//    h7->Rebin(10.);
//    setup1Dhist(h7,colour1,"Energy [keV]","");
//    gPad->SetLogy();
//    h7->Draw();
//    
//    c5->Print("/home/andreas/vip2/thesis/Latex/Figures/root/Plots/sddEnFromGamma.pdf");
    
    f->Close();
    
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
    gPad->SetLogy();
    h12->Draw();
    c8->Print("/home/andreas/vip2/thesis/Latex/Figures/root/Plots/sumEnSpecSmi.pdf");
    

    g->Close();
    
}