#pragma once



// FormBMP �� ���Դϴ�.

class FormBMP : public CFormView
{
	DECLARE_DYNCREATE(FormBMP)

protected:
	FormBMP();           // ���� ����⿡ ���Ǵ� protected �������Դϴ�.
	virtual ~FormBMP();

public:
	enum { IDD = IDD_FORM_BMP };
#ifdef _DEBUG
	virtual void AssertValid() const;
#ifndef _WIN32_WCE
	virtual void Dump(CDumpContext& dc) const;
#endif
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	DECLARE_MESSAGE_MAP()
};

