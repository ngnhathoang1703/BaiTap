#include "Certificate.h"

string Certificate::GetCertificateID()
{
	return CertificateID;
}

string Certificate::GetCertificateName()
{
	return CertificateName;
}

string Certificate::GetCertificateRank()
{
	return CertificateRank;
}

string Certificate::GetCertificateDate()
{
	return CertificateDate;
}

void Certificate::ShowCertifi() 
{
	cout << "CERTIFICATE ID: " << CertificateID << " - Name: " << CertificateName << " - Rank: "
		<< CertificateRank << " - Date: " << CertificateDate << endl;
}

void Certificate::InsertCertifi() 
{
	cout << "CERTIFICATE ID: ";     getline(cin, CertificateID);
	cout << "Name: ";               getline(cin, CertificateName);
	cout << "Rank: ";               getline(cin, CertificateRank);
	cout << "Date: ";               getline(cin, CertificateDate);
}

Certificate::~Certificate()
{

}