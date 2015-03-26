require "ffi"

module Magic8
  extend FFI::Library
  ffi_lib "libeight/libeight.so"

  callback :custom_callback_response, [], :pointer

  class Options < FFI::Struct
    layout :has_additional_response, :int,
           :additional_response, :pointer,
           :has_callback_response, :int,
           :callback_response, :custom_callback_response
  end

  attach_function :eight_setup, [], :void
  attach_function :eight_quick_shake, [], :string
  attach_function :eight_shake, [Options.ptr], :string
end

Magic8.eight_setup

options = Magic8::Options.new
options[:has_additional_response] = 0

options[:has_callback_response] = 1
options[:callback_response] = Proc.new do
  if Time.now.hour < 12
    FFI::MemoryPointer.from_string("No coffee yet - Ask again later")
  else
    FFI::MemoryPointer.from_string("Too tired - Ask again later.")
  end
end

output = [*0..50].map do
  "'#{Magic8.eight_shake(options)}'"
end.uniq.join(", ")

puts output
