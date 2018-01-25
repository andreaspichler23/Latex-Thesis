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


void PlotHistograms6(Int_t colour1, Int_t colour2, Int_t width, Int_t height){
    
    // .x PlotHistograms6.C(4,2,800,600)
    // without a version number of the histogram, root takes the latest one
    SetStyle();
    gROOT->SetBatch(kTRUE); // suppress output
    gROOT->ForceStyle();  // force the current style onto everything
    
    TFile *f = new TFile("/home/andreas/vip2/thesis/Latex/Figures/root/Histograms_6.root","READ");
    TFile *g = new TFile("/home/andreas/vip2/thesis/Latex/Figures/root/Histograms_4.root","READ");
    TFile *h = new TFile("/home/andreas/vip2/thesis/Latex/Figures/root/Histograms_5.root","READ");
    TFile *e = new TFile("/home/andreas/vip2/thesis/Latex/Figures/root/Histograms_Fit.root","READ");
    
    f->ls();
    
    // ---------------------        chapter 6 ---------------------------
    
    TCanvas *c1 = new TCanvas("c1", "c1", width, height);
    TH1F *h1 = (TH1F*)f->Get("withCurrentSum"); // 1 eV binning; already some part rejected
    TH1F *h2 = (TH1F*)f->Get("hScintRejWithCurrent"); // 1 eV binning; rejection with trgid == 2 || trgid == 3 && adc Mul == 1
    h1->Rebin(100);
    h2->Rebin(100);
    setup1Dhist(h1,colour2,"Energy [eV]","Counts #/100 eV");
    setup1Dhist(h2,colour1);
    h1->GetYaxis()->SetRangeUser(1.,2000000.);
    h1->GetXaxis()->SetRangeUser(1000.,40000.);
    h2->GetXaxis()->SetRangeUser(1000.,40000.);
    gPad->SetLogy();
    h1->Draw();
    h2->Draw("same");
    c1->Print("/home/andreas/vip2/thesis/Latex/Figures/root/Plots/rejCompSpectrumLngsWith.pdf");
    
    TCanvas *c2 = new TCanvas("c2", "c2", width, height);
    TH1F *h3 = (TH1F*)f->Get("noCurrentSmallSum"); // 1 eV binning; already some part rejected
    TH1F *h4 = (TH1F*)f->Get("hScintRejNoCurrentSmall"); // 1 eV binning; rejection with trgid == 2 || trgid == 3 && adc Mul == 1
    h3->Rebin(100);
    h4->Rebin(100);
    setup1Dhist(h3,colour2,"Energy [eV]","Counts #/100 eV");
    setup1Dhist(h4,colour1);
    h3->GetYaxis()->SetRangeUser(1.,2000000.);
    h3->GetXaxis()->SetRangeUser(1000.,40000.);
    h4->GetXaxis()->SetRangeUser(1000.,40000.);
    gPad->SetLogy();
    h3->Draw();
    h4->Draw("same");
    c2->Print("/home/andreas/vip2/thesis/Latex/Figures/root/Plots/rejCompSpectrumLngsWithout.pdf");
    
    TCanvas *c3 = new TCanvas("c3", "c3", width, height);
    TH1F *h5 = (TH1F*)f->Get("gammaBgSimSmeared"); // 1 eV binning
    TH1F *h6 = (TH1F*)f->Get("withCurrentSum");
    //h6->Rebin(3.);
    h5->Rebin(100.);
    //hnew->Scale(2.38);
    //h5->Scale(8.77); // for the gamma spectrum I used with less rate
    h5->Scale(19.39); // for the gamma spectrum kaku used
    h6->GetXaxis()->SetRangeUser(6000.,16000.);
    h5->GetXaxis()->SetRangeUser(7000.,15000.);
    //hnew->GetYaxis()->SetRangeUser(0.,3000.);
    gPad->SetLogy();
    setup1Dhist(h5,colour2,"Energy [eV]","Counts #/100 eV");  
    setup1Dhist(h6,colour1); 
    h5->Draw("hist");
    h6->Draw("same");
    c3->Print("/home/andreas/vip2/thesis/Latex/Figures/root/Plots/simDataCompWith.pdf");
    
    TCanvas *c4 = new TCanvas("c4", "c4", width, height);
    TGraph *h7 = (TGraph*)f->Get("gBgRateWithout");
    TGraph *h8 = (TGraph*)f->Get("gBgRateWith");
    h7->GetXaxis()->SetTimeDisplay(1);
    h8->GetXaxis()->SetTimeDisplay(1);
    h7->GetXaxis()->SetTimeFormat("%d.%m");
    h8->GetXaxis()->SetTimeFormat("%d.%m");   
    h7->GetYaxis()->SetRangeUser(0.168,0.179);
    h7->GetXaxis()->SetLimits(1455000000,1501000000);
    h7->GetXaxis()->SetNdivisions(6); 
    setup1Dgraph(h7,colour1, "Time", "Background rate [s^{-1}]");
    setup1Dgraph(h8,colour2);
    h7->Draw();
    h8->Draw("same pl");
    c4->Print("/home/andreas/vip2/thesis/Latex/Figures/root/Plots/bgRateLngs.pdf");
    
    TCanvas *c5 = new TCanvas("c5", "c5", width, height);
    TGraph *h9 = (TGraph*)f->Get("gSourceRateWithout");
    TGraph *h10 = (TGraph*)f->Get("gSourceRateWith");
    h9->GetXaxis()->SetTimeDisplay(1);
    h10->GetXaxis()->SetTimeDisplay(1);
    h9->GetXaxis()->SetTimeFormat("%d.%m");
    h10->GetXaxis()->SetTimeFormat("%d.%m");   
    h9->GetYaxis()->SetRangeUser(0.6,1.);
    h9->GetXaxis()->SetLimits(1455000000,1501000000);
    h9->GetXaxis()->SetNdivisions(6); 
    setup1Dgraph(h9,colour1, "Time", "Source rate [s^{-1}]");
    setup1Dgraph(h10,colour2);
    h9->Draw();
    h10->Draw("same pl");
    c5->Print("/home/andreas/vip2/thesis/Latex/Figures/root/Plots/sourceRateLngs.pdf");
    
    TCanvas *c6 = new TCanvas("c6", "c6", width, height);
    TGraph *h11 = (TGraph*)f->Get("gSdd1TempWith");
    TGraph *h12 = (TGraph*)f->Get("gSdd1TempWithout");
    h11->GetXaxis()->SetTimeDisplay(1);
    h12->GetXaxis()->SetTimeDisplay(1);
    h11->GetXaxis()->SetTimeFormat("%d.%m");
    h12->GetXaxis()->SetTimeFormat("%d.%m");   
    h11->GetYaxis()->SetRangeUser(-172.5,-169.);
    h11->GetXaxis()->SetLimits(1455000000,1501000000);
    h11->GetXaxis()->SetNdivisions(6); 
    setup1Dgraph(h11,colour2, "Time", "Temperature #circC");
    setup1Dgraph(h12,colour1);
    h11->Draw();
    h12->Draw("same pl");
    c6->Print("/home/andreas/vip2/thesis/Latex/Figures/root/Plots/sdd1TempLNGS.pdf");
    
    TCanvas *c7 = new TCanvas("c7", "c7", width, height);
    TGraph *h13 = (TGraph*)f->Get("gSdd2TempWith");
    TGraph *h14 = (TGraph*)f->Get("gSdd2TempWithout");
    h13->GetXaxis()->SetTimeDisplay(1);
    h14->GetXaxis()->SetTimeDisplay(1);
    h13->GetXaxis()->SetTimeFormat("%d.%m");
    h14->GetXaxis()->SetTimeFormat("%d.%m");   
    h13->GetYaxis()->SetRangeUser(-172,-168.5);
    h13->GetXaxis()->SetLimits(1455000000,1501000000);
    h13->GetXaxis()->SetNdivisions(6); 
    setup1Dgraph(h13,colour2, "Time", "Temperature #circC");
    setup1Dgraph(h14,colour1);
    h13->Draw();
    h14->Draw("same pl");
    c7->Print("/home/andreas/vip2/thesis/Latex/Figures/root/Plots/sdd2TempLNGS.pdf");
    
    TCanvas *c8 = new TCanvas("c8", "c8", width, height);
    TGraph *h15 = (TGraph*)f->Get("gSdd1FwhmWith");
    TGraph *h16 = (TGraph*)f->Get("gSdd1FwhmWithout");
    h15->GetXaxis()->SetTimeDisplay(1);
    h16->GetXaxis()->SetTimeDisplay(1);
    h15->GetXaxis()->SetTimeFormat("%d.%m");
    h16->GetXaxis()->SetTimeFormat("%d.%m");   
    h15->GetYaxis()->SetRangeUser(134.,186.);
    h15->GetXaxis()->SetLimits(1455000000,1501000000);
    h15->GetXaxis()->SetNdivisions(6); 
    setup1Dgraph(h15,colour2, "Time", "FWHM @ 6 keV [eV]");
    setup1Dgraph(h16,colour1);
    h15->Draw();
    h16->Draw("same pl");
    c8->Print("/home/andreas/vip2/thesis/Latex/Figures/root/Plots/sdd1FwhmLNGS.pdf"); // typical statistical error: 1-2 eV
    
    TCanvas *c9 = new TCanvas("c9", "c9", width, height);
    TGraph *h17 = (TGraph*)f->Get("gSdd3MnPosWith");
    TGraph *h18 = (TGraph*)f->Get("gSdd3MnPosWithout");
    h17->GetXaxis()->SetTimeDisplay(1);
    h18->GetXaxis()->SetTimeDisplay(1);
    h17->GetXaxis()->SetTimeFormat("%d.%m");
    h18->GetXaxis()->SetTimeFormat("%d.%m");   
    h17->GetYaxis()->SetRangeUser(737.,761.);
    h17->GetXaxis()->SetLimits(1455000000,1501000000);
    h17->GetXaxis()->SetNdivisions(6); 
    setup1Dgraph(h17,colour2, "Time", "Mn Peak [ADC channel]");
    setup1Dgraph(h18,colour1);
    h17->Draw();
    h18->Draw("same pl");
    c9->Print("/home/andreas/vip2/thesis/Latex/Figures/root/Plots/sdd3MnPeakPos.pdf"); // typical statisical error: 1 channel
    
    TCanvas *c10 = new TCanvas("c10", "c10", width, height);
    TH1F *h19 = (TH1F*)f->Get("hEnSpecLngs"); // 1 eV binning; complete spectrum
    h19->Rebin(40);
    //h2->Rebin(100);
    setup1Dhist(h19,colour1,"Energy [eV]","Counts #/40 eV");
    //h19->GetYaxis()->SetRangeUser(1.,2000000.);
    h19->GetXaxis()->SetRangeUser(7000.,14500.);
    h19->GetXaxis()->SetNdivisions(8); 
    gPad->SetLogy();
    h19->Draw();
    c10->Print("/home/andreas/vip2/thesis/Latex/Figures/root/Plots/enSpecLngs1.pdf");
    
    TCanvas *c11 = new TCanvas("c11", "c11", width, height);
    TH1F *h20 = (TH1F*)f->Get("hEnSpecLngs"); // 1 eV binning; complete spectrum
    h20->Rebin(40);
    //h2->Rebin(100);
    setup1Dhist(h20,colour1,"Energy [eV]","Counts #/40 eV");
    //h19->GetYaxis()->SetRangeUser(1.,2000000.);
    h20->GetXaxis()->SetRangeUser(14500.,32000.);
    h20->GetXaxis()->SetNdivisions(8);
   // h2->GetXaxis()->SetRangeUser(1000.,40000.);
    gPad->SetLogy();
    h20->Draw();
    c11->Print("/home/andreas/vip2/thesis/Latex/Figures/root/Plots/enSpecLngs2.pdf");
    
    TCanvas *c12 = new TCanvas("c12", "c12", width, height);
    TGraph *h21 = (TGraph*)f->Get("gStatSigmaCu");
    //h21->GetYaxis()->SetRangeUser(0.168,0.179);
    //h21->GetXaxis()->SetLimits(1455000000,1501000000);
    setup1Dgraph(h21,colour1, "Data Taking Time [days]", "#sigma_{stat} @ 8 keV [eV]");
    h21->Draw();
    c12->Print("/home/andreas/vip2/thesis/Latex/Figures/root/Plots/statSigmaCu.pdf");
    
    TCanvas *c13 = new TCanvas("c13", "c13", width, height);
    TGraph *h22 = (TGraph*)f->Get("gDriftSigmaCu");
    //h21->GetYaxis()->SetRangeUser(0.168,0.179);
    //h21->GetXaxis()->SetLimits(1455000000,1501000000);
    setup1Dgraph(h22,colour1, "Data Taking Time [days]", "#sigma_{det} @ 8 keV [eV]");
    h22->Draw();
    c13->Print("/home/andreas/vip2/thesis/Latex/Figures/root/Plots/driftSigmaCu.pdf");
    
    TCanvas *c14 = new TCanvas("c14", "c14", width, height);
    TGraph *h23 = (TGraph*)f->Get("gTotSigmaCu");
    //h21->GetYaxis()->SetRangeUser(0.168,0.179);
    //h21->GetXaxis()->SetLimits(1455000000,1501000000);
    setup1Dgraph(h23,colour1, "Data Taking Time [days]", "#sigma_{tot} @ 8 keV [eV]");
    h23->Draw();
    c14->Print("/home/andreas/vip2/thesis/Latex/Figures/root/Plots/totSigmaCu.pdf");
    
    TCanvas *c15 = new TCanvas("c15", "c15", width, height);
    TH1F *h24 = (TH1F*)f->Get("hEnSpecLngs"); // 1 eV binning; complete spectrum; 198 days 7 hours =  81 days 10.5 hours with current and 116 days 20 hours no current
    TH1F *h25 = (TH1F*)h->Get("hSddEnSpecSmi"); // 1 eV binning; complete spectrum
    h24->Rebin(40);
    h25->Rebin(40);
    setup1Dhist(h24,colour1,"Energy [eV]","Counts #/40 eV");
    setup1Dhist(h25,colour2);
    h24->Scale(0.00504311866);
    h25->Scale(0.26229508196); // scale both to 1 day of data
    h24->GetXaxis()->SetRangeUser(2000.,15000.);
    gPad->SetLogy();
    h24->Draw("hist");
    h25->Draw("same hist");
    c15->Print("/home/andreas/vip2/thesis/Latex/Figures/root/Plots/enSpecCompLngsSmi.pdf");
    
    TCanvas *c16 = new TCanvas("c16", "c16", width, height);
    TH1F *h26 = (TH1F*)f->Get("sddMulLngs"); // 1 eV binning; complete spectrum
    //h26->Rebin(40);
    //h2->Rebin(100);
    setup1Dhist(h26,colour1,"SDD Multiplicity","");
    //h19->GetYaxis()->SetRangeUser(1.,2000000.);
    //h26->GetXaxis()->SetRangeUser(14500.,32000.);
    //h26->GetXaxis()->SetNdivisions(8);
   // h26->GetXaxis()->SetRangeUser(1000.,40000.);
    gPad->SetLogy();
    h26->Draw();
    c16->Print("/home/andreas/vip2/thesis/Latex/Figures/root/Plots/sddMulLngs.pdf");
    
    TCanvas *c17 = new TCanvas("c17", "c17", width, height);
    TGraph *h27 = (TGraph*)f->Get("gBgWithoutHighBg");
    //TGraph *h8 = (TGraph*)f->Get("gBgRateWith");
    h27->GetXaxis()->SetTimeDisplay(1);
    //h8->GetXaxis()->SetTimeDisplay(1);
    h27->GetXaxis()->SetTimeFormat("%d.%m");
    //h8->GetXaxis()->SetTimeFormat("%d.%m");   
    h27->GetYaxis()->SetRangeUser(0.168,0.3);
    h27->GetXaxis()->SetLimits(1454000000,1501000000);
    h27->GetXaxis()->SetNdivisions(6); 
    setup1Dgraph(h27,colour1, "Time", "Background rate [s^{-1}]");
    //setup1Dgraph(h8,colour2);
    h27->Draw();
    h8->Draw("same pl");
    c17->Print("/home/andreas/vip2/thesis/Latex/Figures/root/Plots/highBgRateLngs.pdf");
    
    TCanvas *c18 = new TCanvas("c18", "c18", width, height);
    TH2F *h28 = (TH2F*)f->Get("hCrossTalk");
    h28->RebinX(20.);
    h28->RebinY(20.); 
    h28->GetYaxis()->SetRangeUser(1000.,6000.);
    h28->GetXaxis()->SetRangeUser(1000.,6000.);
    h28->GetYaxis()->SetTitle("Energy [eV]");
    h28->GetXaxis()->SetTitle("Energy [eV]");
    h28->GetXaxis()->SetNdivisions(6); 
    h28->GetYaxis()->SetNdivisions(6); 
    //setup2Dhist(h28,colour1, "Energy [eV]", "Energy [eV]");
    //setup1Dgraph(h8,colour2);
    h28->Draw();
    c18->Print("/home/andreas/vip2/thesis/Latex/Figures/root/Plots/crossTalk.pdf");
    
    TCanvas *c19 = new TCanvas("c19", "c19", width, 1.5*height); // SDD 4 smi data; 2 ch binning
    c19->Divide(1,2);
    c19->cd(1);
    TH1F *h29 = (TH1F*)e->Get("hcal");
    TF1 *f1 = (TF1*)e->Get("fcnTika1");
    TF1 *f2 = (TF1*)e->Get("fcnMnka1");
    TF1 *f3 = (TF1*)e->Get("fcnCuka1");
    TF1 *f4 = (TF1*)e->Get("fcnShelfMn1");
    TF1 *f5 = (TF1*)e->Get("fcnShelfTi1");
    TF1 *f6 = (TF1*)e->Get("fcnTTiK1");
    TF1 *f7 = (TF1*)e->Get("fcnTMnK1");
    TF1 *f8 = (TF1*)e->Get("fcnEscTika1");
    TF1 *f9 = (TF1*)e->Get("fcnBck");
    h29->GetXaxis()->SetRangeUser(410.,1100.);
    h29->GetYaxis()->SetRangeUser(1.,8000.);
    setup1Dhist(h29,colour1, "ADC Channel", "Counts #/ 2 ch");
    f1->SetLineColor(3);
    f2->SetLineStyle(1);
    //f1->SetLineWidth(4);
    f6->SetLineStyle(1);
    gPad->SetLogy();
    h29->Draw();
    f1->Draw("same");
    f2->Draw("same");
    f3->Draw("same");
    f4->Draw("same");
    f5->Draw("same");
    f6->Draw("same");
    f7->Draw("same");
    f8->Draw("same");
    f9->Draw("same");
    
    c19->cd(2);
    TGraph *h30 = (TGraph*)e->Get("gResid");
    h30->GetXaxis()->SetRangeUser(410.,1100.);
    h30->GetYaxis()->SetRangeUser(-3.5,3.5);
    //h30->GetYaxis()->SetTitleOffset(0);
    h30->GetYaxis()->CenterTitle(kFALSE);
    h30->SetMarkerStyle(19);
    h30->SetMarkerSize(0.8);
    h30->Draw("ap");
    c19->Print("/home/andreas/vip2/thesis/Latex/Figures/root/Plots/calibSpecSmi.pdf");
    
    TCanvas *c20 = new TCanvas("c20", "c20", width, height);
    TF1 *f10 = (TF1*)e->Get("fEv2Ch");
    TGraphErrors *h31 = (TGraphErrors*)e->Get("gEv2ChEr2");
    h31->SetMarkerColor(1);
    h31->SetLineColor(1);
    h31->SetMarkerStyle(19);
    h31->SetMarkerSize(1);
    h31->Draw("ap");
    f10->Draw("same");
    c20->Print("/home/andreas/vip2/thesis/Latex/Figures/root/Plots/ev2Ch1.pdf");
    
    TCanvas *c21 = new TCanvas("c21", "c21", width, height);
    TGraphErrors *h32 = (TGraphErrors*)e->Get("gEv2ChEr1");
    h32->SetMarkerColor(1);
    h32->SetLineColor(1);
    h32->SetLineWidth(2);
    h32->SetMarkerStyle(19);
    h32->SetMarkerSize(1);
    h32->GetXaxis()->SetTitle("Energy [eV]");
    h32->GetYaxis()->SetTitle("ADC Channel");
    h32->Draw("ap");
    c21->Print("/home/andreas/vip2/thesis/Latex/Figures/root/Plots/ev2Ch2.pdf");
    
    f->Close();
    g->Close();
    h->Close();
    e->Close();
    
}