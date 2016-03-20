/*
 Copyright (c) 2014, Robert Hodgin, All rights reserved.
 Copyright (c) 2016, The Cinder Project, All rights reserved.

 This code is intended for use with the Cinder C++ library: http://libcinder.org

 Redistribution and use in source and binary forms, with or without modification, are permitted provided that
 the following conditions are met:

    * Redistributions of source code must retain the above copyright notice, this list of conditions and
	the following disclaimer.
    * Redistributions in binary form must reproduce the above copyright notice, this list of conditions and
	the following disclaimer in the documentation and/or other materials provided with the distribution.

 THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED
 WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A
 PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR
 ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED
 TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
 NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 POSSIBILITY OF SUCH DAMAGE.

 Copyright 2016 Google Inc.
 
 Licensed under the Apache License, Version 2.0 (the "License");
 you may not use this file except in compliance with the License.
 You may obtain a copy of the License at
 
 http://www.apache.org/licenses/LICENSE-2.0
 
 Unless required by applicable law or agreed to in writing, software
 distributed under the License is distributed on an "AS IS" BASIS,
 WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 See the License for the specific language governing permissions and
 limitations under the License.
*/

#pragma once

#include "cinder/vk/Batch.h"
#include "cinder/vk/ShaderProg.h"
#include "cinder/vk/Texture.h"
#include "cinder/vk/VertexBuffer.h"

#include "Ocean.h"
#include "Globals.h"

class FishTornadoApp;
class Shark;
using SharkRef = std::shared_ptr<class Shark>;

class Shark {
public:
	Shark( FishTornadoApp *app );

	static SharkRef			create( FishTornadoApp *app );

	void					update( float time, float dt );
	void					updateForDepthFbo();
	void					updateForMainFbo();
	void					drawToDepthFbo();
	void					draw();
	const ci::vec3&			getPos() const { return mPos; }
	const ci::vec3&			getDir() const { return mDir; }

private:
	FishTornadoApp			*mApp = nullptr;

	float					mTime;
	
	ci::vk::BatchRef		mHiResBatch;
	ci::vk::BatchRef		mLoResBatch;
	bool					mCanDraw = false;
	
	ci::vk::GlslProgRef		mShader;
	ci::vk::TextureRef		mDiffuseTex;
	ci::vk::TextureRef		mNormalsTex;
	
	ci::vec3				mPos;
	ci::vec3				mVel;
	ci::vec3				mDir;
	ci::mat4				mMatrix;	
};
