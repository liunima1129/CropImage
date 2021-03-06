#pragma once

#define SHELLTREEEX_QUICK_CHLDDETECT	0x00000001
#define SHELLTREEEX_KEEP_CHILDREN		0x00000002
#define SHELLTREEEX_EXPAND_ALL			0x00000004
#include "FormListDlg.h"
// CMFCShellTreeCtrlEx
class CMFCShellTreeCtrlEx : public CMFCShellTreeCtrl
{
	DECLARE_DYNAMIC(CMFCShellTreeCtrlEx)
	
public:
	CMFCShellTreeCtrlEx(DWORD dwProp = 0);
	virtual ~CMFCShellTreeCtrlEx();
	void SetRootFolder(LPCTSTR szRootDir, BOOL bFullPath = FALSE, DWORD *pdwProp = NULL);	
	void SetFlagsEx(DWORD dwFlags, BOOL bRefresh);
	DWORD_PTR GetItemDataEx(HTREEITEM hItem) const;
	BOOL SetItemDataEx(HTREEITEM hItem, DWORD_PTR dwData);
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnDeleteItem(int nIDCtl, LPDELETEITEMSTRUCT lpDeleteItemStruct);
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	virtual void PreSubclassWindow();
	FormListDlg* m_pFormListDlg;

	CString m_cRootDir;
	DWORD m_dwProp;
	BOOL m_bFullRootPath;

	void InitTreeEx();
	void RefreshEx();
	BOOL GetRootItemsEx();
	
	BOOL IsCustomRoot() { return !m_cRootDir.IsEmpty(); }
	BOOL GetFullRootPIDL(LPSHELLFOLDER pParentFolder, CStringArray& cDirPartArr, int nIndex, LPAFX_SHELLITEMINFO pItem);
	HRESULT EnumObjects(HTREEITEM hParentItem, LPSHELLFOLDER pParentFolder, LPITEMIDLIST pidlParent);
	virtual void FreeItemData(HTREEITEM hItem, DWORD_PTR dwItemData) {}
	virtual void OnItemInserted(HTREEITEM hItem, LPCTSTR szFolderPath) {}
	
	afx_msg void OnTvnSelchanged(NMHDR *pNMHDR, LRESULT *pResult);
};
