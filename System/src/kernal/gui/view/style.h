
typedef struct ButtonStyle
{
	Color borderColor;
 
	Color startColor; 
	
	Color endColor;

	Color startDownColor; 

	Color endDownColor;

	Color textColor; 

	Corner corner;

} ButtonStyle;

ButtonStyle* ButtonStyleDarkRed();

ButtonStyle* ButtonStyleLightGray();

ButtonStyle* ButtonStyleLightBlue();

ButtonStyle* ButtonStyleDarkBlue();

ButtonStyle* ButtonStyleDarkOrange();
