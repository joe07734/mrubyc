/* Auto generated by make_class_table.rb */

extern struct RBuiltinClass mrbc_class_Object;
extern struct RBuiltinClass mrbc_class_Proc;
extern struct RBuiltinClass mrbc_class_NilClass;
extern struct RBuiltinClass mrbc_class_TrueClass;
extern struct RBuiltinClass mrbc_class_FalseClass;
extern struct RBuiltinClass mrbc_class_Symbol;
extern struct RBuiltinClass mrbc_class_Integer;
extern struct RBuiltinClass mrbc_class_Float;
extern struct RBuiltinClass mrbc_class_String;
extern struct RBuiltinClass mrbc_class_Range;
extern struct RBuiltinClass mrbc_class_Array;
extern struct RBuiltinClass mrbc_class_Hash;
extern struct RBuiltinClass mrbc_class_Exception;
extern struct RClass mrbc_class_NoMemoryError;
extern struct RClass mrbc_class_NotImplementedError;
extern struct RClass mrbc_class_StandardError;
extern struct RClass mrbc_class_ArgumentError;
extern struct RClass mrbc_class_IndexError;
extern struct RClass mrbc_class_IOError;
extern struct RClass mrbc_class_NameError;
extern struct RClass mrbc_class_NoMethodError;
extern struct RClass mrbc_class_RangeError;
extern struct RClass mrbc_class_RuntimeError;
extern struct RClass mrbc_class_TypeError;
extern struct RClass mrbc_class_ZeroDivisionError;
extern struct RBuiltinClass mrbc_class_Math;

#if defined(MRBC_DEFINE_BUILTIN_CLASS_TABLE)
static const struct MRBC_BuiltinClass {
  mrbc_class *cls;
  mrbc_class *super;
} MRBC_BuiltinClass[] = {
  { MRBC_CLASS(Object), 0 },
  { MRBC_CLASS(Proc), MRBC_CLASS(Object) },
  { MRBC_CLASS(NilClass), MRBC_CLASS(Object) },
  { MRBC_CLASS(TrueClass), MRBC_CLASS(Object) },
  { MRBC_CLASS(FalseClass), MRBC_CLASS(Object) },
  { MRBC_CLASS(Symbol), MRBC_CLASS(Object) },
  { MRBC_CLASS(Integer), MRBC_CLASS(Object) },
#if MRBC_USE_FLOAT
  { MRBC_CLASS(Float), MRBC_CLASS(Object) },
#endif
#if MRBC_USE_STRING
  { MRBC_CLASS(String), MRBC_CLASS(Object) },
#endif
  { MRBC_CLASS(Range), MRBC_CLASS(Object) },
  { MRBC_CLASS(Array), MRBC_CLASS(Object) },
  { MRBC_CLASS(Hash), MRBC_CLASS(Object) },
  { MRBC_CLASS(Exception), MRBC_CLASS(Object) },
  { MRBC_CLASS(NoMemoryError), MRBC_CLASS(Exception) },
  { MRBC_CLASS(NotImplementedError), MRBC_CLASS(Exception) },
  { MRBC_CLASS(StandardError), MRBC_CLASS(Exception) },
  { MRBC_CLASS(ArgumentError), MRBC_CLASS(StandardError) },
  { MRBC_CLASS(IndexError), MRBC_CLASS(StandardError) },
  { MRBC_CLASS(IOError), MRBC_CLASS(StandardError) },
  { MRBC_CLASS(NameError), MRBC_CLASS(StandardError) },
  { MRBC_CLASS(NoMethodError), MRBC_CLASS(NameError) },
  { MRBC_CLASS(RangeError), MRBC_CLASS(StandardError) },
  { MRBC_CLASS(RuntimeError), MRBC_CLASS(StandardError) },
  { MRBC_CLASS(TypeError), MRBC_CLASS(StandardError) },
  { MRBC_CLASS(ZeroDivisionError), MRBC_CLASS(StandardError) },
#if MRBC_USE_MATH
  { MRBC_CLASS(Math), 0 },
#endif
};
#endif
