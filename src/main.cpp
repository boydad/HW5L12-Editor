#include "view.h"
#include "model.h"
#include "controller.h"
#include "figures.h"

#include <iostream>
#include <vector>

int main(){
	
	Model model;
	Controller handler(model);
	View presenter(handler);
	
	presenter.start();
	
  return 0;
}
