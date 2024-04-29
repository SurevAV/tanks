#pragma once
#pragma GCC optimize ("O3")

class FloatRectItem {
public:
	float width;
	float height;

	float top;
	float left;
	float right;
	float down;

	float reduceWidth;
	float reduceHeight;


	FloatRectItem() {
		width = 0.0f;
		height = 0.0f;
		top = 0.0f;
		left = 0.0f;
		reduceWidth = 0.0f;
		reduceHeight = 0.0f;
		right = 0.0f;
		down = 0.0f;

	}

	

	FloatRectItem(float rectLeft, float rectTop, float rectWidth = 10.0f, float rectHeight = 10.0f) {
		width = rectWidth;
		height = rectHeight;
		top = rectTop;
		left = rectLeft;

		reduceWidth = rectWidth / 2.0f;
		reduceHeight = rectHeight / 2.0f;

		right = getRight();
		down = getDown();

	}

	void changeLeft(float x) {
		left += x;
		right = getRight();
	}

	void changeTop(float y) {
		top += y;
		down = getDown();
	}

	void setLeft(float x) {
		left = x;
		right = getRight();
	}

	void setTop(float y) {
		top = y;
		down = getDown();
	}

	bool intersects(FloatRectItem item) {
		if (
			left < item.right &&
			right > item.left &&
			top < item.down &&
			down > item.top) {
			return true;
		}
		else {
			return false;
		}
	}


	float centerX() { return left + reduceWidth; }

	float centerY() { return top + reduceHeight; }

	float getRight() { return left + width; }

	float getDown() { return top + height; }


};


//class FloatRectItem {
//public:
//	float width;
//	float height;
//	float top;
//	float left;
//
//	float reduceWidth;
//	float reduceHeight;
//
//
//	FloatRectItem() {
//		width = 0.0f;
//		height = 0.0f;
//		top = 0.0f;
//		left = 0.0f;
//		reduceWidth = 0.0f;
//		reduceHeight = 0.0f;
//
//	}
//
//	FloatRectItem(float rectLeft, float rectTop, float rectWidth = 32.0f, float rectHeight = 32.0f) {
//		width = rectWidth;
//		height = rectHeight;
//		top = rectTop;
//		left = rectLeft;
//
//		reduceWidth = rectWidth / 2.0f;
//		reduceHeight = rectHeight / 2.0f;
//
//	}
//
//	bool intersects(FloatRectItem item) {
//
//		if (left < item.left + item.width &&
//			left + width > item.left &&
//			top < item.top + item.height &&
//			height + top > item.top) {
//			return true;
//		}
//
//		else {
//			return false;
//		}
//
//
//	}
//
//	float centerX() { return left + reduceWidth; }
//
//	float centerY() { return top + reduceHeight; }
//
//	float right() { return left + width; }
//
//	float down() { return top + height; }
//
//
//};