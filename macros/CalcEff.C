#include <TH1.h>

void CalcEff(TH1F hist1, TH1F hist2, TH1F &hist3)
{
/* CalcEff : This macro calculates the efficiency and the error on the 
 *	     the histo2 / histo1 and writes it to histo3. Also the errors
 *           are calculated.
 * Version : 1.00 06 05 1998
 * Author  : Sven Schagen
 */
	char *dummy;
	hist3.Divide(&hist2,&hist1,(float)1.0,(float)1.0,dummy);

	Int_t bins = hist1.GetNbinsX();

	Double_t error[bins];

	for(Int_t i = 0; i < bins; ++i)
	{
		Float_t h1 = hist1.GetBinContent(i);
		Float_t h2 = hist2.GetBinContent(i);
		error[i] = (sqrt((h1 - h1)*h2/h1)/h1);
	}
	hist3.SetError((double *)error);
}
