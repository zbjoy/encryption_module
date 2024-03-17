// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: Person.proto

#ifndef GOOGLE_PROTOBUF_INCLUDED_Person_2eproto
#define GOOGLE_PROTOBUF_INCLUDED_Person_2eproto

#include <limits>
#include <string>

#include <google/protobuf/port_def.inc>
#if PROTOBUF_VERSION < 3008000
#error This file was generated by a newer version of protoc which is
#error incompatible with your Protocol Buffer headers. Please update
#error your headers.
#endif
#if 3008000 < PROTOBUF_MIN_PROTOC_VERSION
#error This file was generated by an older version of protoc which is
#error incompatible with your Protocol Buffer headers. Please
#error regenerate this file with a newer version of protoc.
#endif

#include <google/protobuf/port_undef.inc>
#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/arena.h>
#include <google/protobuf/arenastring.h>
#include <google/protobuf/generated_message_table_driven.h>
#include <google/protobuf/generated_message_util.h>
#include <google/protobuf/inlined_string_field.h>
#include <google/protobuf/metadata.h>
#include <google/protobuf/generated_message_reflection.h>
#include <google/protobuf/message.h>
#include <google/protobuf/repeated_field.h>  // IWYU pragma: export
#include <google/protobuf/extension_set.h>  // IWYU pragma: export
#include <google/protobuf/generated_enum_reflection.h>
#include <google/protobuf/unknown_field_set.h>
#include "Info.pb.h"
// @@protoc_insertion_point(includes)
#include <google/protobuf/port_def.inc>
#define PROTOBUF_INTERNAL_EXPORT_Person_2eproto
PROTOBUF_NAMESPACE_OPEN
namespace internal {
class AnyMetadata;
}  // namespace internal
PROTOBUF_NAMESPACE_CLOSE

// Internal implementation detail -- do not use these members.
struct TableStruct_Person_2eproto {
  static const ::PROTOBUF_NAMESPACE_ID::internal::ParseTableField entries[]
    PROTOBUF_SECTION_VARIABLE(protodesc_cold);
  static const ::PROTOBUF_NAMESPACE_ID::internal::AuxillaryParseTableField aux[]
    PROTOBUF_SECTION_VARIABLE(protodesc_cold);
  static const ::PROTOBUF_NAMESPACE_ID::internal::ParseTable schema[1]
    PROTOBUF_SECTION_VARIABLE(protodesc_cold);
  static const ::PROTOBUF_NAMESPACE_ID::internal::FieldMetadata field_metadata[];
  static const ::PROTOBUF_NAMESPACE_ID::internal::SerializationTable serialization_table[];
  static const ::PROTOBUF_NAMESPACE_ID::uint32 offsets[];
};
extern const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable descriptor_table_Person_2eproto;
namespace Person {
class Person;
class PersonDefaultTypeInternal;
extern PersonDefaultTypeInternal _Person_default_instance_;
}  // namespace Person
PROTOBUF_NAMESPACE_OPEN
template<> ::Person::Person* Arena::CreateMaybeMessage<::Person::Person>(Arena*);
PROTOBUF_NAMESPACE_CLOSE
namespace Person {

enum Type : int {
  Student = 0,
  Teacher = 1,
  Parents = 2,
  Type_INT_MIN_SENTINEL_DO_NOT_USE_ = std::numeric_limits<::PROTOBUF_NAMESPACE_ID::int32>::min(),
  Type_INT_MAX_SENTINEL_DO_NOT_USE_ = std::numeric_limits<::PROTOBUF_NAMESPACE_ID::int32>::max()
};
bool Type_IsValid(int value);
constexpr Type Type_MIN = Student;
constexpr Type Type_MAX = Parents;
constexpr int Type_ARRAYSIZE = Type_MAX + 1;

const ::PROTOBUF_NAMESPACE_ID::EnumDescriptor* Type_descriptor();
template<typename T>
inline const std::string& Type_Name(T enum_t_value) {
  static_assert(::std::is_same<T, Type>::value ||
    ::std::is_integral<T>::value,
    "Incorrect type passed to function Type_Name.");
  return ::PROTOBUF_NAMESPACE_ID::internal::NameOfEnum(
    Type_descriptor(), enum_t_value);
}
inline bool Type_Parse(
    const std::string& name, Type* value) {
  return ::PROTOBUF_NAMESPACE_ID::internal::ParseNamedEnum<Type>(
    Type_descriptor(), name, value);
}
// ===================================================================

class Person :
    public ::PROTOBUF_NAMESPACE_ID::Message /* @@protoc_insertion_point(class_definition:Person.Person) */ {
 public:
  Person();
  virtual ~Person();

  Person(const Person& from);
  Person(Person&& from) noexcept
    : Person() {
    *this = ::std::move(from);
  }

  inline Person& operator=(const Person& from) {
    CopyFrom(from);
    return *this;
  }
  inline Person& operator=(Person&& from) noexcept {
    if (GetArenaNoVirtual() == from.GetArenaNoVirtual()) {
      if (this != &from) InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }

  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* descriptor() {
    return GetDescriptor();
  }
  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* GetDescriptor() {
    return GetMetadataStatic().descriptor;
  }
  static const ::PROTOBUF_NAMESPACE_ID::Reflection* GetReflection() {
    return GetMetadataStatic().reflection;
  }
  static const Person& default_instance();

  static void InitAsDefaultInstance();  // FOR INTERNAL USE ONLY
  static inline const Person* internal_default_instance() {
    return reinterpret_cast<const Person*>(
               &_Person_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    0;

  void Swap(Person* other);
  friend void swap(Person& a, Person& b) {
    a.Swap(&b);
  }

  // implements Message ----------------------------------------------

  inline Person* New() const final {
    return CreateMaybeMessage<Person>(nullptr);
  }

  Person* New(::PROTOBUF_NAMESPACE_ID::Arena* arena) const final {
    return CreateMaybeMessage<Person>(arena);
  }
  void CopyFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) final;
  void MergeFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) final;
  void CopyFrom(const Person& from);
  void MergeFrom(const Person& from);
  PROTOBUF_ATTRIBUTE_REINITIALIZES void Clear() final;
  bool IsInitialized() const final;

  size_t ByteSizeLong() const final;
  #if GOOGLE_PROTOBUF_ENABLE_EXPERIMENTAL_PARSER
  const char* _InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) final;
  #else
  bool MergePartialFromCodedStream(
      ::PROTOBUF_NAMESPACE_ID::io::CodedInputStream* input) final;
  #endif  // GOOGLE_PROTOBUF_ENABLE_EXPERIMENTAL_PARSER
  void SerializeWithCachedSizes(
      ::PROTOBUF_NAMESPACE_ID::io::CodedOutputStream* output) const final;
  ::PROTOBUF_NAMESPACE_ID::uint8* InternalSerializeWithCachedSizesToArray(
      ::PROTOBUF_NAMESPACE_ID::uint8* target) const final;
  int GetCachedSize() const final { return _cached_size_.Get(); }

  private:
  inline void SharedCtor();
  inline void SharedDtor();
  void SetCachedSize(int size) const final;
  void InternalSwap(Person* other);
  friend class ::PROTOBUF_NAMESPACE_ID::internal::AnyMetadata;
  static ::PROTOBUF_NAMESPACE_ID::StringPiece FullMessageName() {
    return "Person.Person";
  }
  private:
  inline ::PROTOBUF_NAMESPACE_ID::Arena* GetArenaNoVirtual() const {
    return nullptr;
  }
  inline void* MaybeArenaPtr() const {
    return nullptr;
  }
  public:

  ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadata() const final;
  private:
  static ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadataStatic() {
    ::PROTOBUF_NAMESPACE_ID::internal::AssignDescriptors(&::descriptor_table_Person_2eproto);
    return ::descriptor_table_Person_2eproto.file_level_metadata[kIndexInFileMessages];
  }

  public:

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  // bytes name = 2;
  void clear_name();
  static const int kNameFieldNumber = 2;
  const std::string& name() const;
  void set_name(const std::string& value);
  void set_name(std::string&& value);
  void set_name(const char* value);
  void set_name(const void* value, size_t size);
  std::string* mutable_name();
  std::string* release_name();
  void set_allocated_name(std::string* name);

  // .Info.Info info = 4;
  bool has_info() const;
  void clear_info();
  static const int kInfoFieldNumber = 4;
  const ::Info::Info& info() const;
  ::Info::Info* release_info();
  ::Info::Info* mutable_info();
  void set_allocated_info(::Info::Info* info);

  // int32 id = 1;
  void clear_id();
  static const int kIdFieldNumber = 1;
  ::PROTOBUF_NAMESPACE_ID::int32 id() const;
  void set_id(::PROTOBUF_NAMESPACE_ID::int32 value);

  // int32 age = 3;
  void clear_age();
  static const int kAgeFieldNumber = 3;
  ::PROTOBUF_NAMESPACE_ID::int32 age() const;
  void set_age(::PROTOBUF_NAMESPACE_ID::int32 value);

  // .Person.Type type = 5;
  void clear_type();
  static const int kTypeFieldNumber = 5;
  ::Person::Type type() const;
  void set_type(::Person::Type value);

  // @@protoc_insertion_point(class_scope:Person.Person)
 private:
  class HasBitSetters;

  ::PROTOBUF_NAMESPACE_ID::internal::InternalMetadataWithArena _internal_metadata_;
  ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr name_;
  ::Info::Info* info_;
  ::PROTOBUF_NAMESPACE_ID::int32 id_;
  ::PROTOBUF_NAMESPACE_ID::int32 age_;
  int type_;
  mutable ::PROTOBUF_NAMESPACE_ID::internal::CachedSize _cached_size_;
  friend struct ::TableStruct_Person_2eproto;
};
// ===================================================================


// ===================================================================

#ifdef __GNUC__
  #pragma GCC diagnostic push
  #pragma GCC diagnostic ignored "-Wstrict-aliasing"
#endif  // __GNUC__
// Person

// int32 id = 1;
inline void Person::clear_id() {
  id_ = 0;
}
inline ::PROTOBUF_NAMESPACE_ID::int32 Person::id() const {
  // @@protoc_insertion_point(field_get:Person.Person.id)
  return id_;
}
inline void Person::set_id(::PROTOBUF_NAMESPACE_ID::int32 value) {
  
  id_ = value;
  // @@protoc_insertion_point(field_set:Person.Person.id)
}

// bytes name = 2;
inline void Person::clear_name() {
  name_.ClearToEmptyNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
}
inline const std::string& Person::name() const {
  // @@protoc_insertion_point(field_get:Person.Person.name)
  return name_.GetNoArena();
}
inline void Person::set_name(const std::string& value) {
  
  name_.SetNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), value);
  // @@protoc_insertion_point(field_set:Person.Person.name)
}
inline void Person::set_name(std::string&& value) {
  
  name_.SetNoArena(
    &::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), ::std::move(value));
  // @@protoc_insertion_point(field_set_rvalue:Person.Person.name)
}
inline void Person::set_name(const char* value) {
  GOOGLE_DCHECK(value != nullptr);
  
  name_.SetNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:Person.Person.name)
}
inline void Person::set_name(const void* value, size_t size) {
  
  name_.SetNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:Person.Person.name)
}
inline std::string* Person::mutable_name() {
  
  // @@protoc_insertion_point(field_mutable:Person.Person.name)
  return name_.MutableNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
}
inline std::string* Person::release_name() {
  // @@protoc_insertion_point(field_release:Person.Person.name)
  
  return name_.ReleaseNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
}
inline void Person::set_allocated_name(std::string* name) {
  if (name != nullptr) {
    
  } else {
    
  }
  name_.SetAllocatedNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), name);
  // @@protoc_insertion_point(field_set_allocated:Person.Person.name)
}

// int32 age = 3;
inline void Person::clear_age() {
  age_ = 0;
}
inline ::PROTOBUF_NAMESPACE_ID::int32 Person::age() const {
  // @@protoc_insertion_point(field_get:Person.Person.age)
  return age_;
}
inline void Person::set_age(::PROTOBUF_NAMESPACE_ID::int32 value) {
  
  age_ = value;
  // @@protoc_insertion_point(field_set:Person.Person.age)
}

// .Info.Info info = 4;
inline bool Person::has_info() const {
  return this != internal_default_instance() && info_ != nullptr;
}
inline const ::Info::Info& Person::info() const {
  const ::Info::Info* p = info_;
  // @@protoc_insertion_point(field_get:Person.Person.info)
  return p != nullptr ? *p : *reinterpret_cast<const ::Info::Info*>(
      &::Info::_Info_default_instance_);
}
inline ::Info::Info* Person::release_info() {
  // @@protoc_insertion_point(field_release:Person.Person.info)
  
  ::Info::Info* temp = info_;
  info_ = nullptr;
  return temp;
}
inline ::Info::Info* Person::mutable_info() {
  
  if (info_ == nullptr) {
    auto* p = CreateMaybeMessage<::Info::Info>(GetArenaNoVirtual());
    info_ = p;
  }
  // @@protoc_insertion_point(field_mutable:Person.Person.info)
  return info_;
}
inline void Person::set_allocated_info(::Info::Info* info) {
  ::PROTOBUF_NAMESPACE_ID::Arena* message_arena = GetArenaNoVirtual();
  if (message_arena == nullptr) {
    delete reinterpret_cast< ::PROTOBUF_NAMESPACE_ID::MessageLite*>(info_);
  }
  if (info) {
    ::PROTOBUF_NAMESPACE_ID::Arena* submessage_arena = nullptr;
    if (message_arena != submessage_arena) {
      info = ::PROTOBUF_NAMESPACE_ID::internal::GetOwnedMessage(
          message_arena, info, submessage_arena);
    }
    
  } else {
    
  }
  info_ = info;
  // @@protoc_insertion_point(field_set_allocated:Person.Person.info)
}

// .Person.Type type = 5;
inline void Person::clear_type() {
  type_ = 0;
}
inline ::Person::Type Person::type() const {
  // @@protoc_insertion_point(field_get:Person.Person.type)
  return static_cast< ::Person::Type >(type_);
}
inline void Person::set_type(::Person::Type value) {
  
  type_ = value;
  // @@protoc_insertion_point(field_set:Person.Person.type)
}

#ifdef __GNUC__
  #pragma GCC diagnostic pop
#endif  // __GNUC__

// @@protoc_insertion_point(namespace_scope)

}  // namespace Person

PROTOBUF_NAMESPACE_OPEN

template <> struct is_proto_enum< ::Person::Type> : ::std::true_type {};
template <>
inline const EnumDescriptor* GetEnumDescriptor< ::Person::Type>() {
  return ::Person::Type_descriptor();
}

PROTOBUF_NAMESPACE_CLOSE

// @@protoc_insertion_point(global_scope)

#include <google/protobuf/port_undef.inc>
#endif  // GOOGLE_PROTOBUF_INCLUDED_GOOGLE_PROTOBUF_INCLUDED_Person_2eproto
