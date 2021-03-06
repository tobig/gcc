
// DO NOT EDIT THIS FILE - it is machine generated -*- c++ -*-

#ifndef __gnu_xml_libxmlj_sax_StringArrayAttributes__
#define __gnu_xml_libxmlj_sax_StringArrayAttributes__

#pragma interface

#include <java/lang/Object.h>
#include <gcj/array.h>

extern "Java"
{
  namespace gnu
  {
    namespace xml
    {
      namespace libxmlj
      {
        namespace sax
        {
            class GnomeXMLReader;
            class StringArrayAttributes;
            class XMLName;
        }
      }
    }
  }
}

class gnu::xml::libxmlj::sax::StringArrayAttributes : public ::java::lang::Object
{

public: // actually package-private
  StringArrayAttributes(::gnu::xml::libxmlj::sax::GnomeXMLReader *, JArray< ::java::lang::String * > *);
public:
  virtual jint getLength();
  virtual ::java::lang::String * getURI(jint);
  virtual ::java::lang::String * getLocalName(jint);
  virtual ::java::lang::String * getQName(jint);
  virtual ::java::lang::String * getType(jint);
  virtual ::java::lang::String * getValue(jint);
  virtual jint getIndex(::java::lang::String *, ::java::lang::String *);
  virtual jint getIndex(::java::lang::String *);
  virtual ::java::lang::String * getType(::java::lang::String *, ::java::lang::String *);
  virtual ::java::lang::String * getType(::java::lang::String *);
  virtual ::java::lang::String * getValue(::java::lang::String *, ::java::lang::String *);
  virtual ::java::lang::String * getValue(::java::lang::String *);
private:
  jint __attribute__((aligned(__alignof__( ::java::lang::Object)))) len;
  JArray< ::gnu::xml::libxmlj::sax::XMLName * > * keys;
  JArray< ::java::lang::String * > * values;
public:
  static ::java::lang::Class class$;
};

#endif // __gnu_xml_libxmlj_sax_StringArrayAttributes__
