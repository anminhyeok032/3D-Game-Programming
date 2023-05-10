#include "stdafx.h"
#include "Scene.h"
#include "GraphicsPipeline.h"

CScene::CScene(CPlayer* pPlayer, CPlayer* pTankBot)
{
	m_pPlayer = pPlayer;
	m_pTankBot = pTankBot;
}

CScene::~CScene()
{
}

void CScene::BuildObjects()
{
	CExplosiveObject::PrepareExplosion();

	float fHalfWidth = 45.0f, fHalfHeight = 45.0f, fHalfDepth = 200.0f;
	CFloorMesh* pFloorMesh = new CFloorMesh(fHalfWidth * 2.0f, fHalfDepth * 2.0f, 30);

	m_pFloorObject = new CFloorObject();
	m_pFloorObject->SetPosition(0.0f, 0.0f, 0.0f);
	m_pFloorObject->SetMesh(pFloorMesh);
	m_pFloorObject->SetColor(RGB(0, 0, 0));
	m_pFloorObject->m_pxmf4FloorPlane = XMFLOAT4(0.0f, +1.0f, 0.0f, 0.0f);

	

	///////////////////////////-
	CTankMesh* m_pTankMesh = new CTankMesh(5.0f, 5.0f, 5.0f);

	m_nTankObject = 9;
	m_ppTankObjects = new CGameObject * [m_nTankObject];
	

	CExplosiveObject *pExplosiveObject1 = new CExplosiveObject();
	pExplosiveObject1 = new CExplosiveObject();
	pExplosiveObject1->SetMesh(m_pTankMesh);
	pExplosiveObject1->SetPosition(-10.0f, 1.0f, 4.0f);
	pExplosiveObject1->SetColor(RGB(255, 64, 64));
	pExplosiveObject1->SetRotationAxis(XMFLOAT3(1.0f, 0.0f, 0.0f));
	pExplosiveObject1->SetRotationSpeed(0.0f); 
	m_ppTankObjects[0] = pExplosiveObject1;

	pExplosiveObject1 = new CExplosiveObject();
	pExplosiveObject1->SetMesh(m_pTankMesh);
	pExplosiveObject1->SetPosition(10.0f, 1.0f, 10.0f);
	pExplosiveObject1->SetColor(RGB(25, 0, 0));
	pExplosiveObject1->SetRotationAxis(XMFLOAT3(1.0f, 0.0f, 0.0f));
	pExplosiveObject1->SetRotationSpeed(0.0f);
	m_ppTankObjects[1] = pExplosiveObject1;

	pExplosiveObject1 = new CExplosiveObject();
	pExplosiveObject1->SetMesh(m_pTankMesh);
	pExplosiveObject1->SetPosition(20.0f, 1.0f, 40.0f);
	pExplosiveObject1->SetColor(RGB(255, 255, 64));
	pExplosiveObject1->SetRotationAxis(XMFLOAT3(1.0f, 0.0f, 0.0f));
	pExplosiveObject1->SetRotationSpeed(0.0f);
	m_ppTankObjects[2] = pExplosiveObject1;

	pExplosiveObject1 = new CExplosiveObject();
	pExplosiveObject1->SetMesh(m_pTankMesh);
	pExplosiveObject1->SetPosition(-20.0f, 1.0f, 40.0f);
	pExplosiveObject1->SetColor(RGB(0, 64, 64));
	pExplosiveObject1->SetRotationAxis(XMFLOAT3(1.0f, 0.0f, 0.0f));
	pExplosiveObject1->SetRotationSpeed(0.0f);
	m_ppTankObjects[3] = pExplosiveObject1;

	pExplosiveObject1 = new CExplosiveObject();
	pExplosiveObject1->SetMesh(m_pTankMesh);
	pExplosiveObject1->SetPosition(-10.0f, 1.0f, 55.0f);
	pExplosiveObject1->SetColor(RGB(50, 64, 64));
	pExplosiveObject1->SetRotationAxis(XMFLOAT3(1.0f, 0.0f, 0.0f));
	pExplosiveObject1->SetRotationSpeed(0.0f);
	m_ppTankObjects[4] = pExplosiveObject1;

	pExplosiveObject1 = new CExplosiveObject();
	pExplosiveObject1->SetMesh(m_pTankMesh);
	pExplosiveObject1->SetPosition(20.0f, 1.0f, 30.0f);
	pExplosiveObject1->SetColor(RGB(0, 64, 255));
	pExplosiveObject1->SetRotationAxis(XMFLOAT3(1.0f, 0.0f, 0.0f));
	pExplosiveObject1->SetRotationSpeed(0.0f);
	m_ppTankObjects[5] = pExplosiveObject1;

	pExplosiveObject1 = new CExplosiveObject();
	pExplosiveObject1->SetMesh(m_pTankMesh);
	pExplosiveObject1->SetPosition(45.0f, 1.0f, 30.0f);
	pExplosiveObject1->SetColor(RGB(50, 255, 64));
	pExplosiveObject1->SetRotationAxis(XMFLOAT3(1.0f, 0.0f, 0.0f));
	pExplosiveObject1->SetRotationSpeed(0.0f);
	m_ppTankObjects[6] = pExplosiveObject1;

	pExplosiveObject1 = new CExplosiveObject();
	pExplosiveObject1->SetMesh(m_pTankMesh);
	pExplosiveObject1->SetPosition(50.0f, 1.0f, 40.0f);
	pExplosiveObject1->SetColor(RGB(10, 64, 64));
	pExplosiveObject1->SetRotationAxis(XMFLOAT3(1.0f, 0.0f, 0.0f));
	pExplosiveObject1->SetRotationSpeed(0.0f);
	m_ppTankObjects[7] = pExplosiveObject1;

	pExplosiveObject1 = new CExplosiveObject();
	pExplosiveObject1->SetMesh(m_pTankMesh);
	pExplosiveObject1->SetPosition(55.0f, 1.0f, 45.0f);
	pExplosiveObject1->SetColor(RGB(20, 64, 64));
	pExplosiveObject1->SetRotationAxis(XMFLOAT3(1.0f, 0.0f, 0.0f));
	pExplosiveObject1->SetRotationSpeed(0.0f);
	m_ppTankObjects[8] = pExplosiveObject1;
	
	


#ifdef _WITH_DRAW_AXIS
	m_pWorldAxis = new CGameObject();
	CAxisMesh* pAxisMesh = new CAxisMesh(0.5f, 0.5f, 0.5f);
	m_pWorldAxis->SetMesh(pAxisMesh);
#endif
}

void CScene::ReleaseObjects()
{
	if (CExplosiveObject::m_pExplosionMesh) CExplosiveObject::m_pExplosionMesh->Release();

	for (int i = 0; i < m_nObjects; i++) if (m_ppObjects[i]) delete m_ppObjects[i];

	for (int i = 0; i < m_nTankObject; i++) if (m_ppTankObjects[i]) delete m_ppTankObjects[i]; //-


	if (m_pFloorObject) delete m_pFloorObject;
	

#ifdef _WITH_DRAW_AXIS
	if (m_pWorldAxis) delete m_pWorldAxis;
#endif
}

void CScene::OnProcessingMouseMessage(HWND hWnd, UINT nMessageID, WPARAM wParam, LPARAM lParam)
{
}

void CScene::OnProcessingKeyboardMessage(HWND hWnd, UINT nMessageID, WPARAM wParam, LPARAM lParam)
{
	switch (nMessageID)
	{
	case WM_KEYDOWN:
		switch (wParam)
		{
		case '1':
		case '2':
		case '3':
		case '4':
		case '5':
		case '6':
		case '7':
		case '8':
		case '9':
		{
			CExplosiveObject* pExplosiveObject = (CExplosiveObject*)m_ppTankObjects[int(wParam - '1')];
			pExplosiveObject->m_bBlowingUp = true;
			break;
		}
		case '0':
			for (int i = 0; i < m_nTankObject; i++)
			{
				CExplosiveObject* pExplosiveObject = (CExplosiveObject*)m_ppTankObjects[i];
				pExplosiveObject->m_bBlowingUp = true;
			}
			break;
		default:
			break;
		}
		break;
	default:
		break;
	}
}

CGameObject* CScene::PickObjectPointedByCursor(int xClient, int yClient, CCamera* pCamera)
{
	XMFLOAT3 xmf3PickPosition;
	xmf3PickPosition.x = (((2.0f * xClient) / (float)pCamera->m_Viewport.m_nWidth) - 1) / pCamera->m_xmf4x4PerspectiveProject._11;
	xmf3PickPosition.y = -(((2.0f * yClient) / (float)pCamera->m_Viewport.m_nHeight) - 1) / pCamera->m_xmf4x4PerspectiveProject._22;
	xmf3PickPosition.z = 1.0f;

	XMVECTOR xmvPickPosition = XMLoadFloat3(&xmf3PickPosition);
	XMMATRIX xmmtxView = XMLoadFloat4x4(&pCamera->m_xmf4x4View);

	int nIntersected = 0;
	float fNearestHitDistance = FLT_MAX;
	CGameObject* pNearestObject = NULL;
	for (int i = 0; i < m_nTankObject; i++)
	{
		float fHitDistance = FLT_MAX;
		nIntersected = m_ppTankObjects[i]->PickObjectByRayIntersection(xmvPickPosition, xmmtxView, &fHitDistance);
		if ((nIntersected > 0) && (fHitDistance < fNearestHitDistance))
		{
			fNearestHitDistance = fHitDistance;
			pNearestObject = m_ppTankObjects[i];
		}
	}
	return(pNearestObject);
}

void CScene::CheckObjectByObjectCollisions()
{


	//////////////////-- 적 tank Object들의 충돌 감지
	for (int i = 0; i < m_nTankObject; i++) m_ppTankObjects[i]->m_pObjectCollided = NULL;
	for (int i = 0; i < m_nTankObject; i++)
	{
		for (int j = (i + 1); j < m_nTankObject; j++)
		{
			if (m_ppTankObjects[i]->m_xmOOBB.Intersects(m_ppTankObjects[j]->m_xmOOBB))
			{
				m_ppTankObjects[i]->m_pObjectCollided = m_ppTankObjects[j];
				m_ppTankObjects[j]->m_pObjectCollided = m_ppTankObjects[i];
			}
		}
	}
	for (int i = 0; i < m_nTankObject; i++)
	{
		if (m_ppTankObjects[i]->m_pObjectCollided)
		{
			XMFLOAT3 xmf3MovingDirection = m_ppTankObjects[i]->m_xmf3MovingDirection;
			float fMovingSpeed = m_ppTankObjects[i]->m_fMovingSpeed;
			m_ppTankObjects[i]->m_xmf3MovingDirection = m_ppTankObjects[i]->m_pObjectCollided->m_xmf3MovingDirection;
			m_ppTankObjects[i]->m_fMovingSpeed = m_ppTankObjects[i]->m_pObjectCollided->m_fMovingSpeed;
			m_ppTankObjects[i]->m_pObjectCollided->m_xmf3MovingDirection = xmf3MovingDirection;
			m_ppTankObjects[i]->m_pObjectCollided->m_fMovingSpeed = fMovingSpeed;
			m_ppTankObjects[i]->m_pObjectCollided->m_pObjectCollided = NULL;
			m_ppTankObjects[i]->m_pObjectCollided = NULL;
		}
		else {
			if (Vector3::Distance(m_pPlayer->GetPosition(), m_ppTankObjects[i]->GetPosition()) < 50) {
				m_ppTankObjects[i]->LookAt(m_pPlayer->GetPosition(), m_ppTankObjects[i]->GetUp());
				m_ppTankObjects[i]->MoveForward(0.25f);
			}
			else {
				if (i & 1) m_ppTankObjects[i]->Rotate(0.0f, m_pPlayer->GetPosition().y, 0.0f);
				else  m_ppTankObjects[i]->Rotate(0.0f, -m_pPlayer->GetPosition().y, 0.0f);
				m_ppTankObjects[i]->MoveForward(0.15f);
			}
		}//- tank object move and rotate
	}

}


void CScene::CheckObjectByBulletCollisions()
{
	CBulletObject** ppBullets = ((CTankPlayer*)m_pPlayer)->m_ppBullets;
	
	for (int i = 0; i < m_nTankObject; i++)
	{
		if (m_ppTankObjects[i]->m_dwColor != RGB(255, 255, 255)) {
			for (int j = 0; j < BULLETS; j++)
			{
				if (ppBullets[j]->m_bActive && m_ppTankObjects[i]->m_xmOOBB.Intersects(ppBullets[j]->m_xmOOBB))
				{
					CExplosiveObject* pExplosiveObject = (CExplosiveObject*)m_ppTankObjects[i];
					pExplosiveObject->m_bBlowingUp = true;
					ppBullets[j]->Reset();	//- TankObject이 총알 맞으면

				}
			}
		}
	}
	if (m_pTankBot->CTankBot_heatNum < 50) {
		for (int j = 0; j < BULLETS; j++)
		{
			if (ppBullets[j]->m_bActive && m_pTankBot->m_xmOOBB.Intersects(ppBullets[j]->m_xmOOBB))
			{
				ppBullets[j]->Reset();	//- 봇이 총알 맞으면
				m_pTankBot->CTankBot_heatNum++;
			}
		}
	}


}


void CScene::Animate(float fElapsedTime)
{
	m_pFloorObject->Animate(fElapsedTime);
	m_pFloorObject->ComputeWorldTransform(NULL);

	
	for (int i = 0; i < m_nTankObject; i++)	if (m_ppTankObjects[i]->m_dwColor != RGB(255, 255, 255)) m_ppTankObjects[i]->Animate(fElapsedTime);
	for (int i = 0; i < m_nTankObject; i++)	if (m_ppTankObjects[i]->m_dwColor != RGB(255, 255, 255)) m_ppTankObjects[i]->ComputeWorldTransform(NULL);//-


	CheckObjectByObjectCollisions();

	CheckObjectByBulletCollisions();
}

void CScene::Render(HDC hDCFrameBuffer, CCamera* pCamera)
{
	CGraphicsPipeline::SetViewport(&pCamera->m_Viewport);
	CGraphicsPipeline::SetViewPerspectiveProjectTransform(&pCamera->m_xmf4x4ViewPerspectiveProject);

	m_pFloorObject->Render(hDCFrameBuffer, pCamera);
	
	for (int i = 0; i < m_nTankObject; i++)	if (m_ppTankObjects[i]->m_dwColor != RGB(255, 255, 255)) m_ppTankObjects[i]->Render(hDCFrameBuffer, pCamera);//-


	if (m_pPlayer) m_pPlayer->Render(hDCFrameBuffer, pCamera);

	if (m_pTankBot) if(m_pTankBot->CTankBot_heatNum < 50 ) m_pTankBot->Render(hDCFrameBuffer, pCamera);

//UI
#ifdef _WITH_DRAW_AXIS
	CGraphicsPipeline::SetViewOrthographicProjectTransform(&pCamera->m_xmf4x4ViewOrthographicProject);
	m_pWorldAxis->SetRotationTransform(&m_pPlayer->m_xmf4x4World);
	m_pWorldAxis->Render(hDCFrameBuffer, pCamera);
#endif
}
