//
//  GLWrapper.cpp
//  GLEssentials
//
//  Created by Denis Zdorovtsov on 24.06.16.
//  Copyright © 2016 Dan Omachi. All rights reserved.
//

#include "GLWrapper.hpp"
#include "glattribarray.h"
#include "glviewshape.h"
#include <OpenGLES/ES2/gl.h>
#include <memory>
#include "glm/mat4x4.hpp"
#include "glm/gtc/matrix_transform.hpp"

extern "C" {

std::shared_ptr<GViewRect> myRect;

void renderCPP() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    
    glm::mat4 pMatrix = glm::ortho(-100, 100, -100, 100, -100, 100);
    glm::mat4 mvMatrix = glm::mat4(1);
    
    if (myRect != nullptr)
        myRect->draw(pMatrix, mvMatrix);

}

void initCPP() {
    glClearColor(0.0, 0.0, 0.0, 0.0);
    CHECK_GL_ERROR;
    glBlendFunc (GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    CHECK_GL_ERROR;
    glEnable (GL_BLEND);
    CHECK_GL_ERROR;
    myRect = std::make_shared<GViewRect>(1000,1000);
}
}