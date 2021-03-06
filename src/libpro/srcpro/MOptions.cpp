/***************************************************************************
 *   Copyright (C) 2010 by Mindaugas Margelevicius                         *
 *   Institute of Biotechnology, Vilnius                                   *
 *   minmar@ibt.lt                                                         *
 *                                                                         *
 ***************************************************************************/

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

#include "rc.h"
#include "ConfigFile.h"
#include "MOptions.h"

// =========================================================================
// global OPTIONS object
MOptions    OPTIONS;

// -------------------------------------------------------------------------
// Constructor
//
MOptions::MOptions( const char* fullname )
:   filename_( fullname )
{
    Init();
}

// -------------------------------------------------------------------------
// Default construction
//
MOptions::MOptions()
:   filename_( NULL )
{
    Init();
}

// -------------------------------------------------------------------------
// Destructor
//
MOptions::~MOptions()
{
}

// -------------------------------------------------------------------------
// Init: Initialization of members
//
void MOptions::Init()
{
    valEVAL_ = defEVAL;
    valNOHITS_ = defNOHITS;
    valNOALNS_ = defNOALNS;
    valSHOW_ = defSHOW;

    valIDENTITY_ = defIDENTITY;
    valDELSTATE_ = defDELSTATE;

    valPCFWEIGHT_ = defPCFWEIGHT;
    valMINALNFRN_ = defMINALNFRN;
    valMINALNPOS_ = defMINALNPOS;
    valSUBMAT_ = defSUBMAT;

    valTFRMIX_ = defTFRMIX;
    valMIXWGT_ = defMIXWGT;
    valSCOADJ_ = defSCOADJ;
    valSUPCLT_ = defSUPCLT;
    valADJWGT_ = defADJWGT;
    valcADJWGT_ = defcADJWGT;

    valCVSWGT_ = defCVSWGT;

    valSSSWGT_ = defSSSWGT;
    valSSSHDP_ = defSSSHDP;

    valSSEMODEL_ = defSSEMODEL;

    valINFCON_ = defINFCON;
    valMASKAFTER_ = defMASKAFTER;
    valSCALEDOWN_ = defSCALEDOWN;

    valHCFILTER_ = defHCFILTER;
    valHCWINDOW_ = defHCWINDOW;
    valHCLOWENT_ = defHCLOWENT;
    valHCHIGHENT_ = defHCHIGHENT;

    valINVLCFILTER_ = defINVLCFILTER;
    valLCFILTEREACH_ = defLCFILTEREACH;
    valLCWINDOW_ = defLCWINDOW;
    valLCLOWENT_ = defLCLOWENT;
    valLCHIGHENT_ = defLCHIGHENT;
    valDISTANCE_ = defDISTANCE;

    valOPENCOST_ = defOPENCOST;
    intOPENCOST_ = defintOPENCOST;
    boolAutoOpenCost_ = defboolAutoOpenCost;
    valEXTCOST_ = defEXTCOST;
    valDELPROBWEIGHT_ = defDELPROBWEIGHT;
    valSCHEME_ = defSCHEME;
    valMINPP_ = defMINPP;
    valCOMPSTATS_ = defCOMPSTATS;
    valUSEGCPROBS_ = defUSEGCPROBS;

    valGPROBEVAL_ = defGPROBEVAL;
    valGPFARGWEIGHT_ = defGPFARGWEIGHT;
    valGPFARGSHIFT_ = defGPFARGSHIFT;

    valAC1NUMER_ = defAC1NUMER;
    valAC2UBNUMER_ = defAC2UBNUMER;
    valAC2LOGSCALE_ = defAC2LOGSCALE;
    valAC2DENOMSCALE_ = defAC2DENOMSCALE;
    valANPOSCOR_ = defANPOSCOR;
    valPROHIBITCOR_ = defPROHIBITCOR;

    valINFCON2UB_ = defINFCON2UB;
    valINFCON2NUMER_ = defINFCON2NUMER;
    valINFCON2LOGSCALE_ = defINFCON2LOGSCALE;
    valINFCONALTNUMER_ = defINFCONALTNUMER;
    valINFCONALTLOGSCALE_ = defINFCONALTLOGSCALE;

    valHSPLEN_ = defHSPLEN;
    valHSPMINSCORE_ = defHSPMINSCORE;
    valHSPMAXDIST_ = defHSPMAXDIST;
    valNOHSPS_ = defNOHSPS;
}

// -------------------------------------------------------------------------
// Read: read options from file
//
void MOptions::Read( const char* filename )
{
    SetFilename( filename );
    Read();
}

// -------------------------------------------------------------------------
// Read: read options from file
//
void MOptions::Read()
{
    ReadEVAL();
    ReadNOHITS();
    ReadNOALNS();
    ReadSHOW();

    ReadIDENTITY();
    ReadDELSTATE();

    ReadPCFWEIGHT();
    ReadMINALNFRN();
    ReadMINALNPOS();
    ReadSUBMAT();

    ReadTFRMIX();
    ReadMIXWGT();
    ReadSCOADJ();
    ReadSUPCLT();
    ReadADJWGT();
    ReadcADJWGT();

    ReadCVSWGT();

    ReadSSSWGT();
    ReadSSSHDP();

    ReadSSEMODEL();

    ReadINFCON();
    ReadMASKAFTER();
    ReadSCALEDOWN();

    ReadHCFILTER();
    ReadHCWINDOW();
    ReadHCLOWENT();
    ReadHCHIGHENT();

    ReadINVLCFILTER();
    ReadLCFILTEREACH();
    ReadLCWINDOW();
    ReadLCLOWENT();
    ReadLCHIGHENT();
    ReadDISTANCE();

    ReadOPENCOST();
    ReadEXTCOST();
    ReadDELPROBWEIGHT();
    ReadSCHEME();
    ReadMINPP();
    ReadCOMPSTATS();
    ReadUSEGCPROBS();

    ReadGPROBEVAL();
    ReadGPFARGWEIGHT();
    ReadGPFARGSHIFT();

    ReadAC1NUMER();
    ReadAC2UBNUMER();
    ReadAC2LOGSCALE();
    ReadAC2DENOMSCALE();
    ReadANPOSCOR();
    ReadPROHIBITCOR();

    ReadINFCON2UB();
    ReadINFCON2NUMER();
    ReadINFCON2LOGSCALE();
    ReadINFCONALTNUMER();
    ReadINFCONALTLOGSCALE();

    ReadHSPLEN();
    ReadHSPMINSCORE();
    ReadHSPMAXDIST();
    ReadNOHSPS();
}

// -------------------------------------------------------------------------

#define MOPTPRIV_INT_KEY( KEY1 ) \
    int         value; \
    const char* section = SECOPTIONS; \
    ConfigFile  config( section, GetFilename()); \
    if( !config.GetInt( KEY1, &value )) \
        return;//not found, return

#define MOPTPRIV_DOUBLE_KEY( KEY1 ) \
    double      value; \
    const char* section = SECOPTIONS; \
    ConfigFile  config( section, GetFilename()); \
    if( !config.GetDouble( KEY1, &value )) \
        return;//not found, return

#define MOPTPRIV_STRING_KEY( KEY1 ) \
    char        value[BUF_MAX]; \
    const char* section = SECOPTIONS; \
    ConfigFile  config( section, GetFilename()); \
    if( !config.GetString( KEY1, value, BUF_MAX )) \
        return;//not found, return

// -------------------------------------------------------------------------
// Output options
//
void MOptions::ReadEVAL()
{
    MOPTPRIV_DOUBLE_KEY( EVAL );
    if( value < 0.0 )
        throw myruntime_error( "E-value threshold specified is negative." );
    valEVAL_ = value;
}

void MOptions::ReadNOHITS()
{
    MOPTPRIV_INT_KEY( NOHITS );
    if( value < 1 )
        throw myruntime_error( "Number of hits specified is invalid." );
    valNOHITS_ = value;
}

void MOptions::ReadNOALNS()
{
    MOPTPRIV_INT_KEY( NOALNS );
    if( value < 1 )
        throw myruntime_error( "Number of alignments specified is invalid." );
    valNOALNS_ = value;
}

void MOptions::ReadSHOW()
{
    MOPTPRIV_INT_KEY( SHOW );
    valSHOW_ = value;
}

// Profile construction options
//
void MOptions::ReadIDENTITY()
{
    MOPTPRIV_INT_KEY( IDENTITY );
    if( value < 1 || 100 < value )
        throw myruntime_error( "Identity threshold is not within interval [1-100]." );
    valIDENTITY_ = value;
}

void MOptions::ReadDELSTATE()
{
    MOPTPRIV_INT_KEY( DELSTATE );
    valDELSTATE_ = value;
}


// ADVANCED OPTIONS:
// Profile construction options
//
void MOptions::ReadPCFWEIGHT()
{
    MOPTPRIV_DOUBLE_KEY( PCFWEIGHT );
    if( value < 0.0 )
        throw myruntime_error( "Weight for pseudocount frequencies should be positive." );
    valPCFWEIGHT_ = value;
}

void MOptions::ReadMINALNFRN()
{
    MOPTPRIV_INT_KEY( MINALNFRN );
    if( value < 1 || 100 < value )
        throw myruntime_error( "Alignment fraction for extent is not within interval [1-100]." );
    valMINALNFRN_ = value;
}

void MOptions::ReadMINALNPOS()
{
    MOPTPRIV_INT_KEY( MINALNPOS );
    if( value < 1 )
        throw myruntime_error( "Min extent length (in pos.) should be positive." );
    valMINALNPOS_ = value;
}

void MOptions::ReadSUBMAT()
{
    MOPTPRIV_STRING_KEY( SUBMAT );
    valSUBMAT_ = value;
}

void MOptions::ReadTFRMIX()
{
    MOPTPRIV_STRING_KEY( TFRMIX );
    valTFRMIX_ = value;
}

void MOptions::ReadMIXWGT()
{
    MOPTPRIV_DOUBLE_KEY( MIXWGT );
    if( value <= 0.0 || 1.0 < value )
        throw myruntime_error("Weight of mixing is not in interval (0-1].");
    valMIXWGT_ = value;
}

void MOptions::ReadSCOADJ()
{
    MOPTPRIV_STRING_KEY( SCOADJ );
    valSCOADJ_ = value;
}

void MOptions::ReadSUPCLT()
{
    MOPTPRIV_INT_KEY( SUPCLT );
    if( value < 1 && value != -1 )
        throw myruntime_error("Number of support clusters should be positive.");
    valSUPCLT_ = value;
}

void MOptions::ReadADJWGT()
{
    MOPTPRIV_DOUBLE_KEY( ADJWGT );
    if( value <= 0.0 || 1.0 <= value )
        throw myruntime_error("Weight of adjusted scores is not in interval (0-1).");
    valADJWGT_ = value;
}

void MOptions::ReadcADJWGT()
{
    MOPTPRIV_DOUBLE_KEY( cADJWGT );
    if( value <= 0.0 || 1.0 <= value )
        throw myruntime_error("Weight for auxiliary scores is not in interval (0-1).");
    valcADJWGT_ = value;
}

void MOptions::ReadCVSWGT()
{
    MOPTPRIV_DOUBLE_KEY( CVSWGT );
    if( value < 0.0 || 1.0 <= value )
        throw myruntime_error("Weight of vector scores is not in interval [0-1).");
    valCVSWGT_ = value;
}

void MOptions::ReadSSSWGT()
{
    MOPTPRIV_DOUBLE_KEY( SSSWGT );
    if( value < 0.0 || 1.0 <= value )
        throw myruntime_error("Weight of SS scores is not in interval [0-1).");
    valSSSWGT_ = value;
}

void MOptions::ReadSSSHDP()
{
    MOPTPRIV_DOUBLE_KEY( SSSHDP );
    if( value < 0.0 || 1.0 <= value )
        throw myruntime_error("Regularizer of SS scores is not in interval [0-1).");
    valSSSHDP_ = value;
}

// model for the estimation of statistical significance
//
void MOptions::ReadSSEMODEL()
{
    MOPTPRIV_INT_KEY( SSEMODEL );
    if( value < 0 || 2 < value )
        throw myruntime_error("Invalid index of a model for the estimation of statistical significance.");
    valSSEMODEL_ = value;
}


// Masking options
//
void MOptions::ReadINFCON()
{
    MOPTPRIV_DOUBLE_KEY( INFCON );
    if( value < 0.0 )
        throw myruntime_error( "Information content threshold specified is negative." );
    valINFCON_ = value;
}

void MOptions::ReadMASKAFTER()
{
    MOPTPRIV_INT_KEY( MASKAFTER );
    valMASKAFTER_ = value;
}

void MOptions::ReadSCALEDOWN()
{
    MOPTPRIV_INT_KEY( SCALEDOWN );
    if( value < 0 || 100 < value )
        throw myruntime_error( "Scaling percentage of masked positions is not within interval [0-100]." );
    valSCALEDOWN_ = value;
}

// SEG options
// HC Filtering
//
void MOptions::ReadHCFILTER()
{
    MOPTPRIV_INT_KEY( HCFILTER );
    valHCFILTER_ = value;
}

void MOptions::ReadHCWINDOW()
{
    MOPTPRIV_INT_KEY( HCWINDOW );
    if( value < 2 )
        throw myruntime_error( "HC window length must be >1." );
    valHCWINDOW_ = value;
}

void MOptions::ReadHCLOWENT()
{
    MOPTPRIV_DOUBLE_KEY( HCLOWENT );
    if( value < 0.0 )
        throw myruntime_error( "HC low entropy threshold is negative." );
    valHCLOWENT_ = value;
}

void MOptions::ReadHCHIGHENT()
{
    MOPTPRIV_DOUBLE_KEY( HCHIGHENT );
    if( value < 0.0 )
        throw myruntime_error( "HC high entropy threshold is negative." );
    valHCHIGHENT_ = value;
}

// LC Filtering
//
void MOptions::ReadINVLCFILTER()
{
    MOPTPRIV_INT_KEY( INVLCFILTER );
    valINVLCFILTER_ = value;
}

void MOptions::ReadLCFILTEREACH()
{
    MOPTPRIV_INT_KEY( LCFILTEREACH );
    valLCFILTEREACH_ = value;
}

void MOptions::ReadLCWINDOW()
{
    MOPTPRIV_INT_KEY( LCWINDOW );
    if( value < 2 )
        throw myruntime_error( "LC window length must be >1." );
    valLCWINDOW_ = value;
}

void MOptions::ReadLCLOWENT()
{
    MOPTPRIV_DOUBLE_KEY( LCLOWENT );
    if( value < 0.0 )
        throw myruntime_error( "LC low entropy threshold is negative." );
    valLCLOWENT_ = value;
}

void MOptions::ReadLCHIGHENT()
{
    MOPTPRIV_DOUBLE_KEY( LCHIGHENT );
    if( value < 0.0 )
        throw myruntime_error( "LC high entropy threshold is negative." );
    valLCHIGHENT_ = value;
}

void MOptions::ReadDISTANCE()
{
    MOPTPRIV_DOUBLE_KEY( DISTANCE );
    if( value < 0.0 )
        throw myruntime_error( "Distance of equivalence is negative." );
    valDISTANCE_ = value;
}

// Alignment options
//
void MOptions::ReadOPENCOST()
{
    MOPTPRIV_STRING_KEY( OPENCOST );
    valOPENCOST_ = value;
}

void MOptions::ReadEXTCOST()
{
    MOPTPRIV_INT_KEY( EXTCOST );
    valEXTCOST_ = -abs( value );
}

void MOptions::ReadDELPROBWEIGHT()
{
    MOPTPRIV_DOUBLE_KEY( DELPROBWEIGHT );
    if( value < 0.0 || 1.0 < value )
        throw myruntime_error( "Deletion probability weight is not within interval [0-1]." );
    valDELPROBWEIGHT_ = value;
}

void MOptions::ReadSCHEME()
{
    MOPTPRIV_STRING_KEY( SCHEME );
    valSCHEME_ = value;
}

void MOptions::ReadMINPP()
{
    MOPTPRIV_DOUBLE_KEY( MINPP );
    if( value < 0.0 || 1.0 <= value )
        throw myruntime_error("Posterior probability threshold is not within interval [0-1).");
    valMINPP_ = value;
}

void MOptions::ReadCOMPSTATS()
{
    MOPTPRIV_INT_KEY( COMPSTATS );
    valCOMPSTATS_ = value;
}

void MOptions::ReadUSEGCPROBS()
{
    MOPTPRIV_INT_KEY( USEGCPROBS );
    valUSEGCPROBS_ = value;
}

// Gap probability options
//
void MOptions::ReadGPROBEVAL()
{
    MOPTPRIV_DOUBLE_KEY( GPROBEVAL );
    if( value < 0.0 )
        throw myruntime_error( "Evalue of gap probability factor to take effect is negative." );
    valGPROBEVAL_ = value;
}

void MOptions::ReadGPFARGWEIGHT()
{
    MOPTPRIV_DOUBLE_KEY( GPFARGWEIGHT );
    if( value < 0.0 )
        throw myruntime_error( "Argument weight in expression of gap probability factor is negative." );
    valGPFARGWEIGHT_ = value;
}

void MOptions::ReadGPFARGSHIFT()
{
    MOPTPRIV_DOUBLE_KEY( GPFARGSHIFT );
    if( 100.0 < value || value < -100.0 )
        throw myruntime_error( "Absolute value of shift in expression of gap probability factor is too large." );
    valGPFARGSHIFT_ = value;
}

// Autocorrection options
//
void MOptions::ReadAC1NUMER()
{
    MOPTPRIV_DOUBLE_KEY( AC1NUMER );
    if( value < 0.0 )
        throw myruntime_error( "Numerator of expression of autocorrection is negative." );
    valAC1NUMER_ = value;
}

void MOptions::ReadAC2UBNUMER()
{
    MOPTPRIV_DOUBLE_KEY( AC2UBNUMER );
    if( value < 0.0 )
        throw myruntime_error( "Numerator of expression for upper bound of autocorrection is negative." );
    valAC2UBNUMER_ = value;
}

void MOptions::ReadAC2LOGSCALE()
{
    MOPTPRIV_DOUBLE_KEY( AC2LOGSCALE );
    if( value < 0.0 )
        throw myruntime_error( "Logarithmic scale in expression of autocorrection is negative." );
    if( 100.0 < value )
        throw myruntime_error( "Logarithmic scale in expression of autocorrection is too large." );
    valAC2LOGSCALE_ = value;
}

void MOptions::ReadAC2DENOMSCALE()
{
    MOPTPRIV_DOUBLE_KEY( AC2DENOMSCALE );
    if( value < 0.0 )
        throw myruntime_error( "Denominator scale in expression of autocorrection is negative." );
    if( 100.0 < value )
        throw myruntime_error( "Denominator scale in expression of autocorrection is too large." );
    valAC2DENOMSCALE_ = value;
}

void MOptions::ReadANPOSCOR()
{
    MOPTPRIV_INT_KEY( ANPOSCOR );
    valANPOSCOR_ = value;
}

void MOptions::ReadPROHIBITCOR()
{
    MOPTPRIV_INT_KEY( PROHIBITCOR );
    valPROHIBITCOR_ = value;
}

//Information correction options
//
void MOptions::ReadINFCON2UB()
{
    MOPTPRIV_DOUBLE_KEY( INFCON2UB );
    if( value < 0.0 )
        throw myruntime_error( "Upper bound of information content threshold is negative." );
    if( 100.0 < value )
        throw myruntime_error( "Upper bound of information content threshold is too large." );
    valINFCON2UB_ = value;
}

void MOptions::ReadINFCON2NUMER()
{
    MOPTPRIV_DOUBLE_KEY( INFCON2NUMER );
    if( value < 0.0 )
        throw myruntime_error( "Numerator of expression of information content is negative." );
    valINFCON2NUMER_ = value;
}

void MOptions::ReadINFCON2LOGSCALE()
{
    MOPTPRIV_DOUBLE_KEY( INFCON2LOGSCALE );
    if( value < 0.0 )
        throw myruntime_error( "Logarithmic scale of expression of information content is negative." );
    if( 100.0 < value )
        throw myruntime_error( "Logarithmic scale of expression of information content is too large." );
    valINFCON2LOGSCALE_ = value;
}

void MOptions::ReadINFCONALTNUMER()
{
    MOPTPRIV_DOUBLE_KEY( INFCONALTNUMER );
    if( value < 0.0 )
        throw myruntime_error( "Numerator of alternative expression of inf. content is negative." );
    if( 100.0 < value )
        throw myruntime_error( "Numerator of alternative expression of inf. content is too large." );
    valINFCONALTNUMER_ = value;
}

void MOptions::ReadINFCONALTLOGSCALE()
{
    MOPTPRIV_DOUBLE_KEY( INFCONALTLOGSCALE );
    if( value < 0.0 )
        throw myruntime_error( "Logarithmic scale of alternative expression of inf. content is negative." );
    if( 100.0 < value )
        throw myruntime_error( "Logarithmic scale of alternative expression of inf. content is too large." );
    valINFCONALTLOGSCALE_ = value;
}

// High-scoring segment pairs
//
void MOptions::ReadHSPLEN()
{
    MOPTPRIV_INT_KEY( HSPLEN );
    if( value < 3 || 50 < value )
        throw myruntime_error( "Length of HSP hit is not valid." );
    valHSPLEN_ = value;
}

void MOptions::ReadHSPMINSCORE()
{
    MOPTPRIV_INT_KEY( HSPMINSCORE );
    if( value < 0 )
        throw myruntime_error( "HSP score is negative." );
    valHSPMINSCORE_ = value;
}

void MOptions::ReadHSPMAXDIST()
{
    MOPTPRIV_INT_KEY( HSPMAXDIST );
    if( value <= 0 )
        throw myruntime_error( "Distance between HSPs is non-positive." );
    valHSPMAXDIST_ = value;
}

void MOptions::ReadNOHSPS()
{
    MOPTPRIV_INT_KEY( NOHSPS );
    if( value < 1 || 10 < value )
        throw myruntime_error( "Number of HSPs is not valid." );
    valNOHSPS_ = value;
}

// -------------------------------------------------------------------------

// Translate open cost to integer values
//
void MOptions::TranslateOPENCOST()
{
    int     value;
    char*   p;

    if( valOPENCOST_.empty())
        return;

    if( valOPENCOST_[0] == 'A' || valOPENCOST_[0] == 'a' ) {
        if( 1 < valOPENCOST_.length()) {
            value = strtol( valOPENCOST_.c_str() + 1, &p, 10 );
            if( errno || *p )
                throw myruntime_error( "Gap open cost: Invalid autocorrelation window size." );
            if( MAX_AUTOCORR_WINDOW_SIZE < value || value < MIN_AUTOCORR_WINDOW_SIZE )
                throw myruntime_error( "Gap open cost: Autocorrelation window size is not within valid interval." );
            intOPENCOST_ = value;
            boolAutoOpenCost_ = true;
        }
    }
    else {
        value = strtol( valOPENCOST_.c_str(), &p, 10 );
        if( errno || *p )
            throw myruntime_error( "Invalid gap open cost." );
        intOPENCOST_ = -abs( value );
        boolAutoOpenCost_ = false;
    }
}
