
// DrawPencilView.cpp : CDrawPencilView 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
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
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CDrawPencilView::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_MOUSEMOVE()
END_MESSAGE_MAP()

// CDrawPencilView 构造/析构

CDrawPencilView::CDrawPencilView()
{
	// TODO:  在此处添加构造代码

}

CDrawPencilView::~CDrawPencilView()
{
}

BOOL CDrawPencilView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO:  在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CDrawPencilView 绘制

void CDrawPencilView::OnDraw(CDC* /*pDC*/)
{
	CDrawPencilDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO:  在此处为本机数据添加绘制代码
}


// CDrawPencilView 打印


void CDrawPencilView::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CDrawPencilView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CDrawPencilView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO:  添加额外的打印前进行的初始化过程
}

void CDrawPencilView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO:  添加打印后进行的清理过程
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


// CDrawPencilView 诊断

#ifdef _DEBUG
void CDrawPencilView::AssertValid() const
{
	CView::AssertValid();
}

void CDrawPencilView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CDrawPencilDoc* CDrawPencilView::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CDrawPencilDoc)));
	return (CDrawPencilDoc*)m_pDocument;
}
#endif //_DEBUG


// CDrawPencilView 消息处理程序


void CDrawPencilView::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值

	//MessageBox(L"View Clicked!");
	m_ptOrigin = point;
	m_bDraw = true;

	CView::OnLButtonDown(nFlags, point);
}

void CDrawPencilView::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值

	m_bDraw = false;

	CView::OnLButtonUp(nFlags, point);
}

void CDrawPencilView::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值

	CClientDC dc(this);
	//创建一个画笔
	CPen pen(PS_SOLID, 1, RGB(255, 0, 0));
	//将创建的画笔选入设备描述表
	CPen *pOldPen = dc.SelectObject(&pen);
	if (m_bDraw == true)
	{
		dc.MoveTo(m_ptOrigin);
		dc.LineTo(point);
		m_ptOrigin = point;  //每次都更新起点
	}


	CView::OnMouseMove(nFlags, point);
}