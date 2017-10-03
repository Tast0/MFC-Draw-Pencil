
// DrawPencilView.h : CDrawPencilView ��Ľӿ�
//

#pragma once


class CDrawPencilView : public CView
{
protected: // �������л�����
	CDrawPencilView();
	DECLARE_DYNCREATE(CDrawPencilView)

// ����
public:
	CDrawPencilDoc* GetDocument() const;

// ����
public:

// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// ʵ��
public:
	virtual ~CDrawPencilView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	afx_msg void OnFilePrintPreview();
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	CPoint m_ptOrigin;
	bool m_bDraw;
};

#ifndef _DEBUG  // DrawPencilView.cpp �еĵ��԰汾
inline CDrawPencilDoc* CDrawPencilView::GetDocument() const
   { return reinterpret_cast<CDrawPencilDoc*>(m_pDocument); }
#endif

