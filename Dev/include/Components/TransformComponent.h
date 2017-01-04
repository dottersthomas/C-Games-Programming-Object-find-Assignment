#ifndef _TRANSFORM_COMPONENT_H_
#define _TRANSFORM_COMPONENT_H_


#include "Component.h"
#include <glm\glm.hpp>
#include <glm\gtx\transform.hpp>
#include <glm\gtc\type_ptr.hpp>


class TransformComponent : public Component {

private:
	glm::vec3 m_Position_ = glm::vec3(0.0f, 0.0f, 0.0f);
	glm::vec3 m_Rotation_ = glm::vec3(0.0f, 0.0f, 0.0f);
	glm::vec3 m_Scale_ = glm::vec3(1.0f, 1.0f, 1.0f);

	glm::mat4 m_Model_;

	bool m_bDirty_;
public:
	
	TransformComponent(Object * pParent);


	void Update(double dt);
	void LateUpdate(double dt);

	void Destroy();
	void Start();

	glm::vec3 getPosition() {
		return m_Position_;
	}

	glm::vec3 getRotation() {
		return m_Rotation_;
	}

	glm::vec3 getScale() {
		return m_Scale_;
	}

	void setPosition(glm::vec3 pPosition) {
		m_Position_ = pPosition;
		m_bDirty_ = true;
	}

	void setRotation(glm::vec3 pRotation) {
		m_Rotation_ = pRotation;
		m_bDirty_ = true;

	}

	void setScale(glm::vec3 pScale) {
		m_Scale_ = pScale;
		m_bDirty_ = true;

	}

	glm::mat4 getModelMatrix() {
		return m_Model_;
	}

};

#endif // !_TRANSFORMCOMPONENT_H_#