//____________________________________________________________________________
/*!

\class    genie::PDF

\brief    A class to store PDFs.

          This class is using the \b Strategy Pattern. \n
          It can accept requests to calculate itself, for a given (x,q^2) pair,
          that it then delegates to the algorithmic object, implementing the
          PDFModelI interface, that it finds attached to itself.

\author   Costas Andreopoulos <C.V.Andreopoulos@rl.ac.uk>
          CCLRC, Rutherford Appleton Laboratory

\created  May 04, 2004

*/
//____________________________________________________________________________

#include "PDF.h"

using namespace genie;

using std::endl;

//____________________________________________________________________________
namespace genie
{
  ostream & operator << (ostream & stream, const PDF & pdf_set)
  {
     pdf_set.Print(stream);
     return stream;
  }
}
//____________________________________________________________________________
PDF::PDF()
{
  this->Init();
}
//____________________________________________________________________________
PDF::PDF(const PDF & pdf_set)
{
  this->Copy(pdf_set);
}
//____________________________________________________________________________
PDF::~PDF()
{

}
//____________________________________________________________________________
void PDF::SetModel(const PDFModelI * model)
{
  this->Init();

  fModel = model;
}
//____________________________________________________________________________
void PDF::Calculate(double x, double q2)
{
  PDF_t pdfs = fModel->AllPDFs(x, q2);

  fUpValence   = pdfs.uval;
  fDownValence = pdfs.dval;
  fUpSea       = pdfs.usea;
  fDownSea     = pdfs.dsea;
  fStrange     = pdfs.str;
  fCharm       = pdfs.chm;
  fBottom      = pdfs.bot;
  fTop         = pdfs.top;
  fGluon       = pdfs.gl;
}
//____________________________________________________________________________
void PDF::ScaleValence(double kscale)
{
  fUpValence   *= kscale;
  fDownValence *= kscale;
}
//____________________________________________________________________________
void PDF::ScaleSea(double kscale)
{
  fUpSea       *= kscale;
  fDownSea     *= kscale;
  fStrange     *= kscale;
  fCharm       *= kscale;
  fBottom      *= kscale;
  fTop         *= kscale;
  fGluon       *= kscale;
}
//____________________________________________________________________________
void PDF::Reset(void)
{
  fUpValence   = 0.0;
  fDownValence = 0.0;
  fUpSea       = 0.0;
  fDownSea     = 0.0;
  fStrange     = 0.0;
  fCharm       = 0.0;
  fBottom      = 0.0;
  fTop         = 0.0;
  fGluon       = 0.0;
}
//____________________________________________________________________________
void PDF::Copy(const PDF & pdf_set)
{
  fModel       = pdf_set.fModel;

  fUpValence   = pdf_set.fUpValence;
  fDownValence = pdf_set.fDownValence;
  fUpSea       = pdf_set.fUpSea;
  fDownSea     = pdf_set.fDownSea;
  fStrange     = pdf_set.fStrange;
  fCharm       = pdf_set.fCharm;
  fBottom      = pdf_set.fBottom;
  fTop         = pdf_set.fTop;
  fGluon       = pdf_set.fGluon;
}
//____________________________________________________________________________
void PDF::Init(void)
{
  fModel = 0;

  fUpValence   = 0.0;
  fDownValence = 0.0;
  fUpSea       = 0.0;
  fDownSea     = 0.0;
  fStrange     = 0.0;
  fCharm       = 0.0;
  fBottom      = 0.0;
  fTop         = 0.0;
  fGluon       = 0.0;
}
//____________________________________________________________________________
void PDF::Print(ostream & stream) const
{
  stream << endl;
  stream << "UP-VAL....... " << fUpValence   << endl;
  stream << "DOWN-VAL..... " << fDownValence << endl;
  stream << "UP-SEA....... " << fUpSea       << endl;
  stream << "DOWN-SEA..... " << fDownSea     << endl;
  stream << "STRANGE...... " << fStrange     << endl;
  stream << "CHARM........ " << fCharm       << endl;
  stream << "BOTTOM....... " << fBottom      << endl;
  stream << "TOP.......... " << fTop         << endl;
  stream << "GLUON........ " << fGluon       << endl;
}
//____________________________________________________________________________

