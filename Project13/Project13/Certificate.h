#pragma once

#include "LibBase.h"

class Certificate
{
private:
	string CertificateID;
	string CertificateName;
	string CertificateRank;
	string CertificateDate;

public:
	void SetCertificateID(const string&);
	void SetCertificateName(const string&);
	void SetCertificateRank(const string&);
	void SetCertificateDate(const string&);
	string GetCertificateID();
	string GetCertificateName();
	string GetCertificateRank();
	string GetCertificateDate();
	void ShowCertifi();
	void InsertCertifi();
	~Certificate();
};