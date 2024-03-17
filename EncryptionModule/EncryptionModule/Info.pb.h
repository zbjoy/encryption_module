// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: Info.proto

#ifndef GOOGLE_PROTOBUF_INCLUDED_Info_2eproto
#define GOOGLE_PROTOBUF_INCLUDED_Info_2eproto

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
#include <google/protobuf/unknown_field_set.h>
// @@protoc_insertion_point(includes)
#include <google/protobuf/port_def.inc>
#define PROTOBUF_INTERNAL_EXPORT_Info_2eproto
PROTOBUF_NAMESPACE_OPEN
namespace internal {
class AnyMetadata;
}  // namespace internal
PROTOBUF_NAMESPACE_CLOSE

// Internal implementation detail -- do not use these members.
struct TableStruct_Info_2eproto {
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
extern const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable descriptor_table_Info_2eproto;
namespace Info {
class Info;
class InfoDefaultTypeInternal;
extern InfoDefaultTypeInternal _Info_default_instance_;
}  // namespace Info
PROTOBUF_NAMESPACE_OPEN
template<> ::Info::Info* Arena::CreateMaybeMessage<::Info::Info>(Arena*);
PROTOBUF_NAMESPACE_CLOSE
namespace Info {

// ===================================================================

class Info :
    public ::PROTOBUF_NAMESPACE_ID::Message /* @@protoc_insertion_point(class_definition:Info.Info) */ {
 public:
  Info();
  virtual ~Info();

  Info(const Info& from);
  Info(Info&& from) noexcept
    : Info() {
    *this = ::std::move(from);
  }

  inline Info& operator=(const Info& from) {
    CopyFrom(from);
    return *this;
  }
  inline Info& operator=(Info&& from) noexcept {
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
  static const Info& default_instance();

  static void InitAsDefaultInstance();  // FOR INTERNAL USE ONLY
  static inline const Info* internal_default_instance() {
    return reinterpret_cast<const Info*>(
               &_Info_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    0;

  void Swap(Info* other);
  friend void swap(Info& a, Info& b) {
    a.Swap(&b);
  }

  // implements Message ----------------------------------------------

  inline Info* New() const final {
    return CreateMaybeMessage<Info>(nullptr);
  }

  Info* New(::PROTOBUF_NAMESPACE_ID::Arena* arena) const final {
    return CreateMaybeMessage<Info>(arena);
  }
  void CopyFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) final;
  void MergeFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) final;
  void CopyFrom(const Info& from);
  void MergeFrom(const Info& from);
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
  void InternalSwap(Info* other);
  friend class ::PROTOBUF_NAMESPACE_ID::internal::AnyMetadata;
  static ::PROTOBUF_NAMESPACE_ID::StringPiece FullMessageName() {
    return "Info.Info";
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
    ::PROTOBUF_NAMESPACE_ID::internal::AssignDescriptors(&::descriptor_table_Info_2eproto);
    return ::descriptor_table_Info_2eproto.file_level_metadata[kIndexInFileMessages];
  }

  public:

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  // bytes address = 2;
  void clear_address();
  static const int kAddressFieldNumber = 2;
  const std::string& address() const;
  void set_address(const std::string& value);
  void set_address(std::string&& value);
  void set_address(const char* value);
  void set_address(const void* value, size_t size);
  std::string* mutable_address();
  std::string* release_address();
  void set_allocated_address(std::string* address);

  // string emil = 3;
  void clear_emil();
  static const int kEmilFieldNumber = 3;
  const std::string& emil() const;
  void set_emil(const std::string& value);
  void set_emil(std::string&& value);
  void set_emil(const char* value);
  void set_emil(const char* value, size_t size);
  std::string* mutable_emil();
  std::string* release_emil();
  void set_allocated_emil(std::string* emil);

  // int32 phoneNum = 1;
  void clear_phonenum();
  static const int kPhoneNumFieldNumber = 1;
  ::PROTOBUF_NAMESPACE_ID::int32 phonenum() const;
  void set_phonenum(::PROTOBUF_NAMESPACE_ID::int32 value);

  // @@protoc_insertion_point(class_scope:Info.Info)
 private:
  class HasBitSetters;

  ::PROTOBUF_NAMESPACE_ID::internal::InternalMetadataWithArena _internal_metadata_;
  ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr address_;
  ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr emil_;
  ::PROTOBUF_NAMESPACE_ID::int32 phonenum_;
  mutable ::PROTOBUF_NAMESPACE_ID::internal::CachedSize _cached_size_;
  friend struct ::TableStruct_Info_2eproto;
};
// ===================================================================


// ===================================================================

#ifdef __GNUC__
  #pragma GCC diagnostic push
  #pragma GCC diagnostic ignored "-Wstrict-aliasing"
#endif  // __GNUC__
// Info

// int32 phoneNum = 1;
inline void Info::clear_phonenum() {
  phonenum_ = 0;
}
inline ::PROTOBUF_NAMESPACE_ID::int32 Info::phonenum() const {
  // @@protoc_insertion_point(field_get:Info.Info.phoneNum)
  return phonenum_;
}
inline void Info::set_phonenum(::PROTOBUF_NAMESPACE_ID::int32 value) {
  
  phonenum_ = value;
  // @@protoc_insertion_point(field_set:Info.Info.phoneNum)
}

// bytes address = 2;
inline void Info::clear_address() {
  address_.ClearToEmptyNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
}
inline const std::string& Info::address() const {
  // @@protoc_insertion_point(field_get:Info.Info.address)
  return address_.GetNoArena();
}
inline void Info::set_address(const std::string& value) {
  
  address_.SetNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), value);
  // @@protoc_insertion_point(field_set:Info.Info.address)
}
inline void Info::set_address(std::string&& value) {
  
  address_.SetNoArena(
    &::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), ::std::move(value));
  // @@protoc_insertion_point(field_set_rvalue:Info.Info.address)
}
inline void Info::set_address(const char* value) {
  GOOGLE_DCHECK(value != nullptr);
  
  address_.SetNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:Info.Info.address)
}
inline void Info::set_address(const void* value, size_t size) {
  
  address_.SetNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:Info.Info.address)
}
inline std::string* Info::mutable_address() {
  
  // @@protoc_insertion_point(field_mutable:Info.Info.address)
  return address_.MutableNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
}
inline std::string* Info::release_address() {
  // @@protoc_insertion_point(field_release:Info.Info.address)
  
  return address_.ReleaseNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
}
inline void Info::set_allocated_address(std::string* address) {
  if (address != nullptr) {
    
  } else {
    
  }
  address_.SetAllocatedNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), address);
  // @@protoc_insertion_point(field_set_allocated:Info.Info.address)
}

// string emil = 3;
inline void Info::clear_emil() {
  emil_.ClearToEmptyNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
}
inline const std::string& Info::emil() const {
  // @@protoc_insertion_point(field_get:Info.Info.emil)
  return emil_.GetNoArena();
}
inline void Info::set_emil(const std::string& value) {
  
  emil_.SetNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), value);
  // @@protoc_insertion_point(field_set:Info.Info.emil)
}
inline void Info::set_emil(std::string&& value) {
  
  emil_.SetNoArena(
    &::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), ::std::move(value));
  // @@protoc_insertion_point(field_set_rvalue:Info.Info.emil)
}
inline void Info::set_emil(const char* value) {
  GOOGLE_DCHECK(value != nullptr);
  
  emil_.SetNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:Info.Info.emil)
}
inline void Info::set_emil(const char* value, size_t size) {
  
  emil_.SetNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:Info.Info.emil)
}
inline std::string* Info::mutable_emil() {
  
  // @@protoc_insertion_point(field_mutable:Info.Info.emil)
  return emil_.MutableNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
}
inline std::string* Info::release_emil() {
  // @@protoc_insertion_point(field_release:Info.Info.emil)
  
  return emil_.ReleaseNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
}
inline void Info::set_allocated_emil(std::string* emil) {
  if (emil != nullptr) {
    
  } else {
    
  }
  emil_.SetAllocatedNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), emil);
  // @@protoc_insertion_point(field_set_allocated:Info.Info.emil)
}

#ifdef __GNUC__
  #pragma GCC diagnostic pop
#endif  // __GNUC__

// @@protoc_insertion_point(namespace_scope)

}  // namespace Info

// @@protoc_insertion_point(global_scope)

#include <google/protobuf/port_undef.inc>
#endif  // GOOGLE_PROTOBUF_INCLUDED_GOOGLE_PROTOBUF_INCLUDED_Info_2eproto
