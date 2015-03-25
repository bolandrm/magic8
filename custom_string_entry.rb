require "ffi"

module Magic8
  extend FFI::Library
  ffi_lib "libeight/libeight.so"

  class Options < FFI::Struct
    layout :has_additional_response, :int,
           :additional_response, :pointer
  end

  attach_function :eight_setup, [], :void
  attach_function :eight_quick_shake, [], :string
  attach_function :eight_shake, [Options.ptr], :string
end

Magic8.eight_setup

options = Magic8::Options.new
options[:has_additional_response] = 1
options[:additional_response] = FFI::MemoryPointer.from_string('Not on my watch!!')

20.times do
  puts Magic8.eight_shake(options)
end
