#pragma once

#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <string>
#include <memory>

class IFigure{     
public:
  virtual const std::vector<std::string>& showAttributeNames() const = 0;
  
  virtual void set(const std::string& attribureName, const std::string& value) = 0;  
  
  virtual std::unique_ptr<IFigure> clone() const = 0;
  
  virtual int getId() = 0;
  
  virtual const char* getName() = 0;
  
  virtual ~IFigure() = default;
  
};


class FigureBase: public IFigure{
protected:
  std::unordered_map<std::string, int> attributes;
  const int id;
  const char* name;
  
static int generateUniqueId(){
  static int tmp = 0;
  tmp++;
  return tmp;
}
  
public:
  
  FigureBase(const char* name): id(generateUniqueId()), name(name) {};
  
  FigureBase(const FigureBase& other): attributes(other.attributes),
        id(generateUniqueId()) {};    
  virtual ~FigureBase() = default;
  FigureBase& operator=(const FigureBase& other) = delete; 
  
  virtual void set(const std::string& name, 
        const std::string& attribute) override{
    attributes[name] = stoi(attribute);
  }   
  
  virtual int getId() override{
    return id;
  }
  
  virtual const char* getName() override {
    return name;
  }
  
};


class Line: public FigureBase{        
public:  
  
  Line(): FigureBase("Line") {};
  
  virtual const std::vector<std::string>& showAttributeNames() const final{
    static const std::vector<std::string> names {"Length", 
          "X coordinate", "Y coordinate"};
    return names;
  }

  virtual std::unique_ptr<IFigure> clone() const override{
    return std::unique_ptr<IFigure>(new Line(*this));
  }    
};


class Box: public FigureBase{
public:  
  
  Box(): FigureBase("Box") {};
  
  virtual const std::vector<std::string>& showAttributeNames() const final{
    static const std::vector<std::string> names {"Width", 
          "X coordinate", "Y coordinate"};
    return names;
  }
  
  virtual std::unique_ptr<IFigure> clone() const override{
    return std::unique_ptr<IFigure>(new Box(*this));
  } 
};


class Circle: public FigureBase{
public: 
  
  Circle(): FigureBase("Circle") {};
  
  virtual const std::vector<std::string>& showAttributeNames() const final{
    static const std::vector<std::string> names {"Radius", 
          "X coordinate", "Y coordinate"};
    return names;
  }
  
  virtual std::unique_ptr<IFigure> clone() const override{
    return std::unique_ptr<IFigure>(new Circle(*this));
  }      
};


class Point: public IFigure{
  int x, y;
  const char* name;
  
public:
  
  Point(): name("Point") {};
  
  virtual const char* getName() override {
    return name;
  }
  
  virtual const std::vector<std::string>& showAttributeNames() const final{
    static const std::vector<std::string> names {"X coordinate", 
          "Y coordinate"};
    return names;
  }
  
  virtual std::unique_ptr<IFigure> clone() const override{
    return std::unique_ptr<IFigure>(new Point(*this));
  } 
  
  virtual void set(const std::string& name, 
        const std::string& attribute) override{
    const int tmp = stoi(attribute);;
    if(name.compare("X coordinate") == 0)
      x = tmp;
    else if(name.compare("Y coordinate") == 0)
      y = tmp;
  };     
  
  virtual int getId() override{    
    return 0;
  }
  
};