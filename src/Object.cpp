#include "Object.h"

Object::Object(const float& width, const float& height, const std::shared_ptr<Board>& board)
	:
	m_Board(board),
	m_Width(width),
	m_Height(height)
{

}
