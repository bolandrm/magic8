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

  attach_function :setup, :eight_setup, [], :void
  attach_function :quick_shake, :eight_quick_shake, [], :string
  attach_function :shake, :eight_shake, [Options.ptr], :string
end

Magic8.setup

options = Magic8::Options.new
options[:has_additional_response] = 0

options[:has_callback_response] = 1
options[:callback_response] = Proc.new do
  if Time.now.hour < 12
    response = "No coffee yet - Ask again later"
  else
    response = "Too tired - Ask again later."
  end

  FFI::MemoryPointer.from_string(response)
end

output = [*0..50].map do
  "'#{Magic8.shake(options)}'"
end.uniq.join(", ")

puts output
