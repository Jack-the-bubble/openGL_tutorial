#include "VertexArray.h"
#include "Renderer.h"

VertexArray::VertexArray()
{
	GLcall(glGenVertexArrays(1, &m_RendererID));
}

VertexArray::~VertexArray()
{
	GLcall(glDeleteVertexArrays(1, &m_RendererID));
}

void VertexArray::bind() const
{
	GLcall(glBindVertexArray(m_RendererID));
}

void VertexArray::unbind() const
{
	GLcall(glBindVertexArray(0));
}

void VertexArray::addBuffer(const VertexBuffer& vb, const VertexBufferLayout& layout)
{
	bind();
	vb.Bind();
	const auto& elements = layout.getElements();
	unsigned int offset = 0;
	for (unsigned int i = 0; i < elements.size(); i++)
	{
		const auto& element = elements[i];
		glEnableVertexAttribArray(0);
		glVertexAttribPointer(i, element.count, element.type, 
			element.normalized, layout.getStride(), (const void*)offset);
		offset += element.count* VertexBufferElement::getSizeOfType(element.type);
	}
	
}
