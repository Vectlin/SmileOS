#include "../../const/const.h"
#include "../../type/type.h"
#include "../sheet.h"
#include "../color.h"
#include "../corner.h"
#include "view.h"
#include "event.h"
#include "../image.h"
#include "../graphics.h"
#include "graphPanel.h"

static void initGraphPanel(GraphPanel *this);

static void drawBackground(GraphPanel *this, int width, int height);

static void drawGridView(GraphPanel *this, int width, int height);

static void drawCoorindate(GraphPanel *this, int width, int height);

static void drawBorder(GraphPanel *this, int width, int height);

static void onMouseDown(View *this, MouseEvent *event);

GraphPanel *createGraphPanel(int x, int y, int w, int h)
{
	GraphPanel *graphPanel = (GraphPanel *)alloc(sizeof(GraphPanel));
	graphPanel = (GraphPanel*)initWithViewFunction((View*)graphPanel, x, y, w, h);
	(*graphPanel).canvas = createView(x, y, w, h);	
	(*graphPanel).initPanel = initGraphPanel;
	(*graphPanel).initPanel(graphPanel);
	(*graphPanel).view.onMouseDown = onMouseDown;
	
	return graphPanel;
}

static void initGraphPanel(GraphPanel *this)
{
	if (this!=null) {		
		int width = (*this).view.width;
		int height = (*this).view.height;
		
		drawBackground(this, width, height);		
		drawGridView(this, width, height);
		drawCoorindate(this, width, height);
		drawBorder(this, width, height);
	}
}

static void drawBackground(GraphPanel *this, int width, int height)
{
	Color color;
    color.red = 30;
    color.green = 50;
    color.blue = 70;
	
	drawRect((View *)this, 0, 0, width, height, color);
}

static void drawGridView(GraphPanel *this, int width, int height)
{
	Color color;
    color.red = 50;
    color.green = 70;
    color.blue = 90;

	drawLine((View *)this, 10, 10, width-10, 10, color, LINE_THIN);
	drawLine((View *)this, width-10, 10, width-10, height-10, color, LINE_THIN);	

	int i=0;
	for (i=1;i<=11;++i) {
		drawLine((View *)this, 10, i*40+10, width-10, i*40+10, color, LINE_THIN);	
	}
	
	for (i=1;i<=6;++i) {
		drawLine((View *)this, i*120, 10, i*120, height-10, color, LINE_THIN);	
	}
}

static void drawCoorindate(GraphPanel *this, int width, int height)
{
	Color color;
    color.red = 160;
    color.green = 180;
    color.blue = 200;

	drawLine((View *)this, 10, height-10, width-10, height-10, color, LINE_BOLD);
	drawLine((View *)this, 10, 10, 10, height-10, color, LINE_BOLD);

	int i=0;
	for (i=1;i<=11;++i) {
		drawLine((View *)this, 10, i*40+10, 14, i*40+10, color, LINE_THIN);	
	}
	
	for (i=1;i<=6;++i) {
		drawLine((View *)this, i*120, height-14, i*120, height-10, color, LINE_THIN);	
	}
}

static void drawBorder(GraphPanel *this, int width, int height)
{
	Color color;
	color.red = 80;
    color.green = 100;
    color.blue = 120;
	
	drawLine((View *)this, 0, 0, width, 0, color, LINE_THIN);
	drawLine((View *)this, 0, 0, 0, height, color, LINE_THIN);
	drawLine((View *)this, 0, height-1, width, height-1, color, LINE_THIN);
	drawLine((View *)this, width-1, 0, width-1, height, color, LINE_THIN);
}

static void onMouseDown(View *this, MouseEvent *event)
{}
