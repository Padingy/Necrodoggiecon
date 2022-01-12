#include "CMeshComponent.h"
#include "Engine.h"

CMeshComponent::CMeshComponent()
{
	mesh = new CMesh();
}

void CMeshComponent::Update(float deltaTime)
{

}

void CMeshComponent::Draw(ID3D11DeviceContext* context)
{
	// Set vertex buffer
	UINT stride = sizeof(SimpleVertex);
	UINT offset = 0;
	Engine::deviceContext->IASetVertexBuffers(0, 1, &mesh->vertexBuffer, &stride, &offset);

	// Set index buffer
	Engine::deviceContext->IASetIndexBuffer(mesh->indexBuffer, DXGI_FORMAT_R16_UINT, 0);

	// Set primitive topology
	Engine::deviceContext->IASetPrimitiveTopology(D3D11_PRIMITIVE_TOPOLOGY_TRIANGLELIST);

	Engine::deviceContext->PSSetConstantBuffers(1, 1, &mesh->materialConstantBuffer);

	context->PSSetShaderResources(0, 1, &mesh->textureResourceView);
	context->PSSetSamplers(0, 1, &mesh->samplerLinear);
	
	context->DrawIndexed(6, 0, 0);
}

CMeshComponent::~CMeshComponent()
{
	delete mesh;
}
