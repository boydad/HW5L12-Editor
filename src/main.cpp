#include "view.h"
#include "model.h"
#include "controller.h"

#include <iostream>

int main(){
	
	Model model;
	Controller handler(model);
	View presenter(handler);
	
	presenter.start();
	
  return 0;
}
