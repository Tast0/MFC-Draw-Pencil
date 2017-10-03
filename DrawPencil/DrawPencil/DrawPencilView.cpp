
// DrawPencilView.cpp : CDrawPencilView ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "DrawPencil.h"
#endif

#include "DrawPencilDoc.h"
#include "DrawPencilView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CDrawPencilView

IMPLEMENT_DYNCREATE(CDrawPencilView, CView)

BEGIN_MESSAGE_MAP(CDrawPencilView, CView)
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CDrawPencilView::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_MOUSEMOVE()
END_MESSAGE_MAP()

// CDrawPencilView ����/����

CDrawPencilView::CDrawPencilView()
{
	// TODO:  �ڴ˴���ӹ������

}

CDrawPencilView::~CDrawPencilView()
{
}

BOOL CDrawPencilView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO:  �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CDrawPencilView ����

void CDrawPencilView::OnDraw(CDC* /*pDC*/)
{
	CDrawPencilDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO:  �ڴ˴�Ϊ����������ӻ��ƴ���
}


// CDrawPencilView ��ӡ


void CDrawPencilView::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CDrawPencilView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void CDrawPencilView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO:  ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void CDrawPencilView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO:  ��Ӵ�ӡ����е��������
}

void CDrawPencilView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CDrawPencilView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CDrawPencilView ���

#ifdef _DEBUG
void CDrawPencilView::AssertValid() const
{
	CView::AssertValid();
}

void CDrawPencilView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CDrawPencilDoc* CDrawPencilView::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CDrawPencilDoc)));
	return (CDrawPencilDoc*)m_pDocument;
}
#endif //_DEBUG


// CDrawPencilView ��Ϣ�������


void CDrawPencilView::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ

	//MessageBox(L"View Clicked!");
	m_ptOrigin = point;
	m_bDraw = true;

	CView::OnLButtonDown(nFlags, point);
}

void CDrawPencilView::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ

	m_bDraw = false;

	CView::OnLButtonUp(nFlags, point);
}

void CDrawPencilView::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ

	CClientDC dc(this);
	//����һ������
	CPen pen(PS_SOLID, 1, RGB(255, 0, 0));
	//�������Ļ���ѡ���豸������
	CPen *pOldPen = dc.SelectObject(&pen);
	if (m_bDraw == true)
	{
		dc.MoveTo(m_ptOrigin);
		dc.LineTo(point);
		m_ptOrigin = point;  //ÿ�ζ��������
	}


	CView::OnMouseMove(nFlags, point);
}