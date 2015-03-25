require "ffi"

module Magic8
  extend FFI::Library
  ffi_lib "libeight/libeight.so"

  attach_function :eight_setup, [], :void
  attach_function :eight_quick_shake, [], :string
end

Magic8.eight_setup
puts Magic8.eight_quick_shake
