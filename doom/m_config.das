options gen2
options solid_context = true
options stack = 4194304
module m_config public

require c2da_runtime
require i_system_cluster
require m_argv
require strings
require daslib/fio
var private c2da_str_0 : array<int8> = [int8(109), int8(111), int8(117), int8(115), int8(101), int8(95), int8(115), int8(101), int8(110), int8(115), int8(105), int8(116), int8(105), int8(118), int8(105), int8(116), int8(121), int8(0)]

var private c2da_str_1 : array<int8> = [int8(115), int8(102), int8(120), int8(95), int8(118), int8(111), int8(108), int8(117), int8(109), int8(101), int8(0)]

var private c2da_str_2 : array<int8> = [int8(109), int8(117), int8(115), int8(105), int8(99), int8(95), int8(118), int8(111), int8(108), int8(117), int8(109), int8(101), int8(0)]

var private c2da_str_3 : array<int8> = [int8(115), int8(104), int8(111), int8(119), int8(95), int8(116), int8(97), int8(108), int8(107), int8(0)]

var private c2da_str_4 : array<int8> = [int8(118), int8(111), int8(105), int8(99), int8(101), int8(95), int8(118), int8(111), int8(108), int8(117), int8(109), int8(101), int8(0)]

var private c2da_str_5 : array<int8> = [int8(115), int8(104), int8(111), int8(119), int8(95), int8(109), int8(101), int8(115), int8(115), int8(97), int8(103), int8(101), int8(115), int8(0)]

var private c2da_str_6 : array<int8> = [int8(107), int8(101), int8(121), int8(95), int8(114), int8(105), int8(103), int8(104), int8(116), int8(0)]

var private c2da_str_7 : array<int8> = [int8(107), int8(101), int8(121), int8(95), int8(108), int8(101), int8(102), int8(116), int8(0)]

var private c2da_str_8 : array<int8> = [int8(107), int8(101), int8(121), int8(95), int8(117), int8(112), int8(0)]

var private c2da_str_9 : array<int8> = [int8(107), int8(101), int8(121), int8(95), int8(100), int8(111), int8(119), int8(110), int8(0)]

var private c2da_str_10 : array<int8> = [int8(107), int8(101), int8(121), int8(95), int8(115), int8(116), int8(114), int8(97), int8(102), int8(101), int8(108), int8(101), int8(102), int8(116), int8(0)]

var private c2da_str_11 : array<int8> = [int8(107), int8(101), int8(121), int8(95), int8(115), int8(116), int8(114), int8(97), int8(102), int8(101), int8(114), int8(105), int8(103), int8(104), int8(116), int8(0)]

var private c2da_str_12 : array<int8> = [int8(107), int8(101), int8(121), int8(95), int8(117), int8(115), int8(101), int8(72), int8(101), int8(97), int8(108), int8(116), int8(104), int8(0)]

var private c2da_str_13 : array<int8> = [int8(107), int8(101), int8(121), int8(95), int8(106), int8(117), int8(109), int8(112), int8(0)]

var private c2da_str_14 : array<int8> = [int8(107), int8(101), int8(121), int8(95), int8(102), int8(108), int8(121), int8(117), int8(112), int8(0)]

var private c2da_str_15 : array<int8> = [int8(107), int8(101), int8(121), int8(95), int8(102), int8(108), int8(121), int8(100), int8(111), int8(119), int8(110), int8(0)]

var private c2da_str_16 : array<int8> = [int8(107), int8(101), int8(121), int8(95), int8(102), int8(108), int8(121), int8(99), int8(101), int8(110), int8(116), int8(101), int8(114), int8(0)]

var private c2da_str_17 : array<int8> = [int8(107), int8(101), int8(121), int8(95), int8(108), int8(111), int8(111), int8(107), int8(117), int8(112), int8(0)]

var private c2da_str_18 : array<int8> = [int8(107), int8(101), int8(121), int8(95), int8(108), int8(111), int8(111), int8(107), int8(100), int8(111), int8(119), int8(110), int8(0)]

var private c2da_str_19 : array<int8> = [int8(107), int8(101), int8(121), int8(95), int8(108), int8(111), int8(111), int8(107), int8(99), int8(101), int8(110), int8(116), int8(101), int8(114), int8(0)]

var private c2da_str_20 : array<int8> = [int8(107), int8(101), int8(121), int8(95), int8(105), int8(110), int8(118), int8(113), int8(117), int8(101), int8(114), int8(121), int8(0)]

var private c2da_str_21 : array<int8> = [int8(107), int8(101), int8(121), int8(95), int8(109), int8(105), int8(115), int8(115), int8(105), int8(111), int8(110), int8(0)]

var private c2da_str_22 : array<int8> = [int8(107), int8(101), int8(121), int8(95), int8(105), int8(110), int8(118), int8(80), int8(111), int8(112), int8(0)]

var private c2da_str_23 : array<int8> = [int8(107), int8(101), int8(121), int8(95), int8(105), int8(110), int8(118), int8(75), int8(101), int8(121), int8(0)]

var private c2da_str_24 : array<int8> = [int8(107), int8(101), int8(121), int8(95), int8(105), int8(110), int8(118), int8(72), int8(111), int8(109), int8(101), int8(0)]

var private c2da_str_25 : array<int8> = [int8(107), int8(101), int8(121), int8(95), int8(105), int8(110), int8(118), int8(69), int8(110), int8(100), int8(0)]

var private c2da_str_26 : array<int8> = [int8(107), int8(101), int8(121), int8(95), int8(105), int8(110), int8(118), int8(108), int8(101), int8(102), int8(116), int8(0)]

var private c2da_str_27 : array<int8> = [int8(107), int8(101), int8(121), int8(95), int8(105), int8(110), int8(118), int8(114), int8(105), int8(103), int8(104), int8(116), int8(0)]

var private c2da_str_28 : array<int8> = [int8(107), int8(101), int8(121), int8(95), int8(105), int8(110), int8(118), int8(76), int8(101), int8(102), int8(116), int8(0)]

var private c2da_str_29 : array<int8> = [int8(107), int8(101), int8(121), int8(95), int8(105), int8(110), int8(118), int8(82), int8(105), int8(103), int8(104), int8(116), int8(0)]

var private c2da_str_30 : array<int8> = [int8(107), int8(101), int8(121), int8(95), int8(117), int8(115), int8(101), int8(97), int8(114), int8(116), int8(105), int8(102), int8(97), int8(99), int8(116), int8(0)]

var private c2da_str_31 : array<int8> = [int8(107), int8(101), int8(121), int8(95), int8(105), int8(110), int8(118), int8(85), int8(115), int8(101), int8(0)]

var private c2da_str_32 : array<int8> = [int8(107), int8(101), int8(121), int8(95), int8(105), int8(110), int8(118), int8(68), int8(114), int8(111), int8(112), int8(0)]

var private c2da_str_33 : array<int8> = [int8(107), int8(101), int8(121), int8(95), int8(108), int8(111), int8(111), int8(107), int8(85), int8(112), int8(0)]

var private c2da_str_34 : array<int8> = [int8(107), int8(101), int8(121), int8(95), int8(108), int8(111), int8(111), int8(107), int8(68), int8(111), int8(119), int8(110), int8(0)]

var private c2da_str_35 : array<int8> = [int8(107), int8(101), int8(121), int8(95), int8(102), int8(105), int8(114), int8(101), int8(0)]

var private c2da_str_36 : array<int8> = [int8(107), int8(101), int8(121), int8(95), int8(117), int8(115), int8(101), int8(0)]

var private c2da_str_37 : array<int8> = [int8(107), int8(101), int8(121), int8(95), int8(115), int8(116), int8(114), int8(97), int8(102), int8(101), int8(0)]

var private c2da_str_38 : array<int8> = [int8(107), int8(101), int8(121), int8(95), int8(115), int8(112), int8(101), int8(101), int8(100), int8(0)]

var private c2da_str_39 : array<int8> = [int8(117), int8(115), int8(101), int8(95), int8(109), int8(111), int8(117), int8(115), int8(101), int8(0)]

var private c2da_str_40 : array<int8> = [int8(109), int8(111), int8(117), int8(115), int8(101), int8(98), int8(95), int8(102), int8(105), int8(114), int8(101), int8(0)]

var private c2da_str_41 : array<int8> = [int8(109), int8(111), int8(117), int8(115), int8(101), int8(98), int8(95), int8(115), int8(116), int8(114), int8(97), int8(102), int8(101), int8(0)]

var private c2da_str_42 : array<int8> = [int8(109), int8(111), int8(117), int8(115), int8(101), int8(98), int8(95), int8(102), int8(111), int8(114), int8(119), int8(97), int8(114), int8(100), int8(0)]

var private c2da_str_43 : array<int8> = [int8(109), int8(111), int8(117), int8(115), int8(101), int8(98), int8(95), int8(106), int8(117), int8(109), int8(112), int8(0)]

var private c2da_str_44 : array<int8> = [int8(117), int8(115), int8(101), int8(95), int8(106), int8(111), int8(121), int8(115), int8(116), int8(105), int8(99), int8(107), int8(0)]

var private c2da_str_45 : array<int8> = [int8(106), int8(111), int8(121), int8(98), int8(95), int8(102), int8(105), int8(114), int8(101), int8(0)]

var private c2da_str_46 : array<int8> = [int8(106), int8(111), int8(121), int8(98), int8(95), int8(115), int8(116), int8(114), int8(97), int8(102), int8(101), int8(0)]

var private c2da_str_47 : array<int8> = [int8(106), int8(111), int8(121), int8(98), int8(95), int8(117), int8(115), int8(101), int8(0)]

var private c2da_str_48 : array<int8> = [int8(106), int8(111), int8(121), int8(98), int8(95), int8(115), int8(112), int8(101), int8(101), int8(100), int8(0)]

var private c2da_str_49 : array<int8> = [int8(106), int8(111), int8(121), int8(98), int8(95), int8(106), int8(117), int8(109), int8(112), int8(0)]

var private c2da_str_50 : array<int8> = [int8(115), int8(99), int8(114), int8(101), int8(101), int8(110), int8(98), int8(108), int8(111), int8(99), int8(107), int8(115), int8(0)]

var private c2da_str_51 : array<int8> = [int8(115), int8(99), int8(114), int8(101), int8(101), int8(110), int8(115), int8(105), int8(122), int8(101), int8(0)]

var private c2da_str_52 : array<int8> = [int8(100), int8(101), int8(116), int8(97), int8(105), int8(108), int8(108), int8(101), int8(118), int8(101), int8(108), int8(0)]

var private c2da_str_53 : array<int8> = [int8(115), int8(110), int8(100), int8(95), int8(99), int8(104), int8(97), int8(110), int8(110), int8(101), int8(108), int8(115), int8(0)]

var private c2da_str_54 : array<int8> = [int8(115), int8(110), int8(100), int8(95), int8(109), int8(117), int8(115), int8(105), int8(99), int8(100), int8(101), int8(118), int8(105), int8(99), int8(101), int8(0)]

var private c2da_str_55 : array<int8> = [int8(115), int8(110), int8(100), int8(95), int8(115), int8(102), int8(120), int8(100), int8(101), int8(118), int8(105), int8(99), int8(101), int8(0)]

var private c2da_str_56 : array<int8> = [int8(115), int8(110), int8(100), int8(95), int8(115), int8(98), int8(112), int8(111), int8(114), int8(116), int8(0)]

var private c2da_str_57 : array<int8> = [int8(115), int8(110), int8(100), int8(95), int8(115), int8(98), int8(105), int8(114), int8(113), int8(0)]

var private c2da_str_58 : array<int8> = [int8(115), int8(110), int8(100), int8(95), int8(115), int8(98), int8(100), int8(109), int8(97), int8(0)]

var private c2da_str_59 : array<int8> = [int8(115), int8(110), int8(100), int8(95), int8(109), int8(112), int8(111), int8(114), int8(116), int8(0)]

var private c2da_str_60 : array<int8> = [int8(117), int8(115), int8(101), int8(103), int8(97), int8(109), int8(109), int8(97), int8(0)]

var private c2da_str_61 : array<int8> = [int8(115), int8(97), int8(118), int8(101), int8(100), int8(105), int8(114), int8(0)]

var private c2da_str_62 : array<int8> = [int8(109), int8(101), int8(115), int8(115), int8(97), int8(103), int8(101), int8(115), int8(111), int8(110), int8(0)]

var private c2da_str_63 : array<int8> = [int8(98), int8(97), int8(99), int8(107), int8(95), int8(102), int8(108), int8(97), int8(116), int8(0)]

var private c2da_str_64 : array<int8> = [int8(110), int8(105), int8(99), int8(107), int8(110), int8(97), int8(109), int8(101), int8(0)]

var private c2da_str_65 : array<int8> = [int8(99), int8(104), int8(97), int8(116), int8(109), int8(97), int8(99), int8(114), int8(111), int8(48), int8(0)]

var private c2da_str_66 : array<int8> = [int8(99), int8(104), int8(97), int8(116), int8(109), int8(97), int8(99), int8(114), int8(111), int8(49), int8(0)]

var private c2da_str_67 : array<int8> = [int8(99), int8(104), int8(97), int8(116), int8(109), int8(97), int8(99), int8(114), int8(111), int8(50), int8(0)]

var private c2da_str_68 : array<int8> = [int8(99), int8(104), int8(97), int8(116), int8(109), int8(97), int8(99), int8(114), int8(111), int8(51), int8(0)]

var private c2da_str_69 : array<int8> = [int8(99), int8(104), int8(97), int8(116), int8(109), int8(97), int8(99), int8(114), int8(111), int8(52), int8(0)]

var private c2da_str_70 : array<int8> = [int8(99), int8(104), int8(97), int8(116), int8(109), int8(97), int8(99), int8(114), int8(111), int8(53), int8(0)]

var private c2da_str_71 : array<int8> = [int8(99), int8(104), int8(97), int8(116), int8(109), int8(97), int8(99), int8(114), int8(111), int8(54), int8(0)]

var private c2da_str_72 : array<int8> = [int8(99), int8(104), int8(97), int8(116), int8(109), int8(97), int8(99), int8(114), int8(111), int8(55), int8(0)]

var private c2da_str_73 : array<int8> = [int8(99), int8(104), int8(97), int8(116), int8(109), int8(97), int8(99), int8(114), int8(111), int8(56), int8(0)]

var private c2da_str_74 : array<int8> = [int8(99), int8(104), int8(97), int8(116), int8(109), int8(97), int8(99), int8(114), int8(111), int8(57), int8(0)]

var private c2da_str_75 : array<int8> = [int8(99), int8(111), int8(109), int8(112), int8(111), int8(114), int8(116), int8(0)]

var private c2da_str_76 : array<int8> = [int8(103), int8(114), int8(97), int8(112), int8(104), int8(105), int8(99), int8(97), int8(108), int8(95), int8(115), int8(116), int8(97), int8(114), int8(116), int8(117), int8(112), int8(0)]

var private c2da_str_77 : array<int8> = [int8(97), int8(117), int8(116), int8(111), int8(97), int8(100), int8(106), int8(117), int8(115), int8(116), int8(95), int8(118), int8(105), int8(100), int8(101), int8(111), int8(95), int8(115), int8(101), int8(116), int8(116), int8(105), int8(110), int8(103), int8(115), int8(0)]

var private c2da_str_78 : array<int8> = [int8(102), int8(117), int8(108), int8(108), int8(115), int8(99), int8(114), int8(101), int8(101), int8(110), int8(0)]

var private c2da_str_79 : array<int8> = [int8(97), int8(115), int8(112), int8(101), int8(99), int8(116), int8(95), int8(114), int8(97), int8(116), int8(105), int8(111), int8(95), int8(99), int8(111), int8(114), int8(114), int8(101), int8(99), int8(116), int8(0)]

var private c2da_str_80 : array<int8> = [int8(115), int8(116), int8(97), int8(114), int8(116), int8(117), int8(112), int8(95), int8(100), int8(101), int8(108), int8(97), int8(121), int8(0)]

var private c2da_str_81 : array<int8> = [int8(115), int8(99), int8(114), int8(101), int8(101), int8(110), int8(95), int8(119), int8(105), int8(100), int8(116), int8(104), int8(0)]

var private c2da_str_82 : array<int8> = [int8(115), int8(99), int8(114), int8(101), int8(101), int8(110), int8(95), int8(104), int8(101), int8(105), int8(103), int8(104), int8(116), int8(0)]

var private c2da_str_83 : array<int8> = [int8(115), int8(99), int8(114), int8(101), int8(101), int8(110), int8(95), int8(98), int8(112), int8(112), int8(0)]

var private c2da_str_84 : array<int8> = [int8(103), int8(114), int8(97), int8(98), int8(109), int8(111), int8(117), int8(115), int8(101), int8(0)]

var private c2da_str_85 : array<int8> = [int8(110), int8(111), int8(118), int8(101), int8(114), int8(116), int8(0)]

var private c2da_str_86 : array<int8> = [int8(109), int8(111), int8(117), int8(115), int8(101), int8(95), int8(97), int8(99), int8(99), int8(101), int8(108), int8(101), int8(114), int8(97), int8(116), int8(105), int8(111), int8(110), int8(0)]

var private c2da_str_87 : array<int8> = [int8(109), int8(111), int8(117), int8(115), int8(101), int8(95), int8(116), int8(104), int8(114), int8(101), int8(115), int8(104), int8(111), int8(108), int8(100), int8(0)]

var private c2da_str_88 : array<int8> = [int8(115), int8(110), int8(100), int8(95), int8(115), int8(97), int8(109), int8(112), int8(108), int8(101), int8(114), int8(97), int8(116), int8(101), int8(0)]

var private c2da_str_89 : array<int8> = [int8(115), int8(110), int8(100), int8(95), int8(99), int8(97), int8(99), int8(104), int8(101), int8(115), int8(105), int8(122), int8(101), int8(0)]

var private c2da_str_90 : array<int8> = [int8(115), int8(110), int8(100), int8(95), int8(109), int8(97), int8(120), int8(115), int8(108), int8(105), int8(99), int8(101), int8(116), int8(105), int8(109), int8(101), int8(95), int8(109), int8(115), int8(0)]

var private c2da_str_91 : array<int8> = [int8(115), int8(110), int8(100), int8(95), int8(109), int8(117), int8(115), int8(105), int8(99), int8(99), int8(109), int8(100), int8(0)]

var private c2da_str_92 : array<int8> = [int8(111), int8(112), int8(108), int8(95), int8(105), int8(111), int8(95), int8(112), int8(111), int8(114), int8(116), int8(0)]

var private c2da_str_93 : array<int8> = [int8(115), int8(104), int8(111), int8(119), int8(95), int8(101), int8(110), int8(100), int8(111), int8(111), int8(109), int8(0)]

var private c2da_str_94 : array<int8> = [int8(112), int8(110), int8(103), int8(95), int8(115), int8(99), int8(114), int8(101), int8(101), int8(110), int8(115), int8(104), int8(111), int8(116), int8(115), int8(0)]

var private c2da_str_95 : array<int8> = [int8(118), int8(97), int8(110), int8(105), int8(108), int8(108), int8(97), int8(95), int8(115), int8(97), int8(118), int8(101), int8(103), int8(97), int8(109), int8(101), int8(95), int8(108), int8(105), int8(109), int8(105), int8(116), int8(0)]

var private c2da_str_96 : array<int8> = [int8(118), int8(97), int8(110), int8(105), int8(108), int8(108), int8(97), int8(95), int8(100), int8(101), int8(109), int8(111), int8(95), int8(108), int8(105), int8(109), int8(105), int8(116), int8(0)]

var private c2da_str_97 : array<int8> = [int8(118), int8(97), int8(110), int8(105), int8(108), int8(108), int8(97), int8(95), int8(107), int8(101), int8(121), int8(98), int8(111), int8(97), int8(114), int8(100), int8(95), int8(109), int8(97), int8(112), int8(112), int8(105), int8(110), int8(103), int8(0)]

var private c2da_str_98 : array<int8> = [int8(118), int8(105), int8(100), int8(101), int8(111), int8(95), int8(100), int8(114), int8(105), int8(118), int8(101), int8(114), int8(0)]

var private c2da_str_99 : array<int8> = [int8(119), int8(105), int8(110), int8(100), int8(111), int8(119), int8(95), int8(112), int8(111), int8(115), int8(105), int8(116), int8(105), int8(111), int8(110), int8(0)]

var private c2da_str_100 : array<int8> = [int8(106), int8(111), int8(121), int8(115), int8(116), int8(105), int8(99), int8(107), int8(95), int8(105), int8(110), int8(100), int8(101), int8(120), int8(0)]

var private c2da_str_101 : array<int8> = [int8(106), int8(111), int8(121), int8(115), int8(116), int8(105), int8(99), int8(107), int8(95), int8(120), int8(95), int8(97), int8(120), int8(105), int8(115), int8(0)]

var private c2da_str_102 : array<int8> = [int8(106), int8(111), int8(121), int8(115), int8(116), int8(105), int8(99), int8(107), int8(95), int8(120), int8(95), int8(105), int8(110), int8(118), int8(101), int8(114), int8(116), int8(0)]

var private c2da_str_103 : array<int8> = [int8(106), int8(111), int8(121), int8(115), int8(116), int8(105), int8(99), int8(107), int8(95), int8(121), int8(95), int8(97), int8(120), int8(105), int8(115), int8(0)]

var private c2da_str_104 : array<int8> = [int8(106), int8(111), int8(121), int8(115), int8(116), int8(105), int8(99), int8(107), int8(95), int8(121), int8(95), int8(105), int8(110), int8(118), int8(101), int8(114), int8(116), int8(0)]

var private c2da_str_105 : array<int8> = [int8(106), int8(111), int8(121), int8(115), int8(116), int8(105), int8(99), int8(107), int8(95), int8(115), int8(116), int8(114), int8(97), int8(102), int8(101), int8(95), int8(97), int8(120), int8(105), int8(115), int8(0)]

var private c2da_str_106 : array<int8> = [int8(106), int8(111), int8(121), int8(115), int8(116), int8(105), int8(99), int8(107), int8(95), int8(115), int8(116), int8(114), int8(97), int8(102), int8(101), int8(95), int8(105), int8(110), int8(118), int8(101), int8(114), int8(116), int8(0)]

var private c2da_str_107 : array<int8> = [int8(106), int8(111), int8(121), int8(115), int8(116), int8(105), int8(99), int8(107), int8(95), int8(112), int8(104), int8(121), int8(115), int8(105), int8(99), int8(97), int8(108), int8(95), int8(98), int8(117), int8(116), int8(116), int8(111), int8(110), int8(48), int8(0)]

var private c2da_str_108 : array<int8> = [int8(106), int8(111), int8(121), int8(115), int8(116), int8(105), int8(99), int8(107), int8(95), int8(112), int8(104), int8(121), int8(115), int8(105), int8(99), int8(97), int8(108), int8(95), int8(98), int8(117), int8(116), int8(116), int8(111), int8(110), int8(49), int8(0)]

var private c2da_str_109 : array<int8> = [int8(106), int8(111), int8(121), int8(115), int8(116), int8(105), int8(99), int8(107), int8(95), int8(112), int8(104), int8(121), int8(115), int8(105), int8(99), int8(97), int8(108), int8(95), int8(98), int8(117), int8(116), int8(116), int8(111), int8(110), int8(50), int8(0)]

var private c2da_str_110 : array<int8> = [int8(106), int8(111), int8(121), int8(115), int8(116), int8(105), int8(99), int8(107), int8(95), int8(112), int8(104), int8(121), int8(115), int8(105), int8(99), int8(97), int8(108), int8(95), int8(98), int8(117), int8(116), int8(116), int8(111), int8(110), int8(51), int8(0)]

var private c2da_str_111 : array<int8> = [int8(106), int8(111), int8(121), int8(115), int8(116), int8(105), int8(99), int8(107), int8(95), int8(112), int8(104), int8(121), int8(115), int8(105), int8(99), int8(97), int8(108), int8(95), int8(98), int8(117), int8(116), int8(116), int8(111), int8(110), int8(52), int8(0)]

var private c2da_str_112 : array<int8> = [int8(106), int8(111), int8(121), int8(115), int8(116), int8(105), int8(99), int8(107), int8(95), int8(112), int8(104), int8(121), int8(115), int8(105), int8(99), int8(97), int8(108), int8(95), int8(98), int8(117), int8(116), int8(116), int8(111), int8(110), int8(53), int8(0)]

var private c2da_str_113 : array<int8> = [int8(106), int8(111), int8(121), int8(115), int8(116), int8(105), int8(99), int8(107), int8(95), int8(112), int8(104), int8(121), int8(115), int8(105), int8(99), int8(97), int8(108), int8(95), int8(98), int8(117), int8(116), int8(116), int8(111), int8(110), int8(54), int8(0)]

var private c2da_str_114 : array<int8> = [int8(106), int8(111), int8(121), int8(115), int8(116), int8(105), int8(99), int8(107), int8(95), int8(112), int8(104), int8(121), int8(115), int8(105), int8(99), int8(97), int8(108), int8(95), int8(98), int8(117), int8(116), int8(116), int8(111), int8(110), int8(55), int8(0)]

var private c2da_str_115 : array<int8> = [int8(106), int8(111), int8(121), int8(115), int8(116), int8(105), int8(99), int8(107), int8(95), int8(112), int8(104), int8(121), int8(115), int8(105), int8(99), int8(97), int8(108), int8(95), int8(98), int8(117), int8(116), int8(116), int8(111), int8(110), int8(56), int8(0)]

var private c2da_str_116 : array<int8> = [int8(106), int8(111), int8(121), int8(115), int8(116), int8(105), int8(99), int8(107), int8(95), int8(112), int8(104), int8(121), int8(115), int8(105), int8(99), int8(97), int8(108), int8(95), int8(98), int8(117), int8(116), int8(116), int8(111), int8(110), int8(57), int8(0)]

var private c2da_str_117 : array<int8> = [int8(106), int8(111), int8(121), int8(98), int8(95), int8(115), int8(116), int8(114), int8(97), int8(102), int8(101), int8(108), int8(101), int8(102), int8(116), int8(0)]

var private c2da_str_118 : array<int8> = [int8(106), int8(111), int8(121), int8(98), int8(95), int8(115), int8(116), int8(114), int8(97), int8(102), int8(101), int8(114), int8(105), int8(103), int8(104), int8(116), int8(0)]

var private c2da_str_119 : array<int8> = [int8(106), int8(111), int8(121), int8(98), int8(95), int8(109), int8(101), int8(110), int8(117), int8(95), int8(97), int8(99), int8(116), int8(105), int8(118), int8(97), int8(116), int8(101), int8(0)]

var private c2da_str_120 : array<int8> = [int8(106), int8(111), int8(121), int8(98), int8(95), int8(112), int8(114), int8(101), int8(118), int8(119), int8(101), int8(97), int8(112), int8(111), int8(110), int8(0)]

var private c2da_str_121 : array<int8> = [int8(106), int8(111), int8(121), int8(98), int8(95), int8(110), int8(101), int8(120), int8(116), int8(119), int8(101), int8(97), int8(112), int8(111), int8(110), int8(0)]

var private c2da_str_122 : array<int8> = [int8(109), int8(111), int8(117), int8(115), int8(101), int8(98), int8(95), int8(115), int8(116), int8(114), int8(97), int8(102), int8(101), int8(108), int8(101), int8(102), int8(116), int8(0)]

var private c2da_str_123 : array<int8> = [int8(109), int8(111), int8(117), int8(115), int8(101), int8(98), int8(95), int8(115), int8(116), int8(114), int8(97), int8(102), int8(101), int8(114), int8(105), int8(103), int8(104), int8(116), int8(0)]

var private c2da_str_124 : array<int8> = [int8(109), int8(111), int8(117), int8(115), int8(101), int8(98), int8(95), int8(117), int8(115), int8(101), int8(0)]

var private c2da_str_125 : array<int8> = [int8(109), int8(111), int8(117), int8(115), int8(101), int8(98), int8(95), int8(98), int8(97), int8(99), int8(107), int8(119), int8(97), int8(114), int8(100), int8(0)]

var private c2da_str_126 : array<int8> = [int8(109), int8(111), int8(117), int8(115), int8(101), int8(98), int8(95), int8(112), int8(114), int8(101), int8(118), int8(119), int8(101), int8(97), int8(112), int8(111), int8(110), int8(0)]

var private c2da_str_127 : array<int8> = [int8(109), int8(111), int8(117), int8(115), int8(101), int8(98), int8(95), int8(110), int8(101), int8(120), int8(116), int8(119), int8(101), int8(97), int8(112), int8(111), int8(110), int8(0)]

var private c2da_str_128 : array<int8> = [int8(100), int8(99), int8(108), int8(105), int8(99), int8(107), int8(95), int8(117), int8(115), int8(101), int8(0)]

var private c2da_str_129 : array<int8> = [int8(107), int8(101), int8(121), int8(95), int8(112), int8(97), int8(117), int8(115), int8(101), int8(0)]

var private c2da_str_130 : array<int8> = [int8(107), int8(101), int8(121), int8(95), int8(109), int8(101), int8(110), int8(117), int8(95), int8(97), int8(99), int8(116), int8(105), int8(118), int8(97), int8(116), int8(101), int8(0)]

var private c2da_str_131 : array<int8> = [int8(107), int8(101), int8(121), int8(95), int8(109), int8(101), int8(110), int8(117), int8(95), int8(117), int8(112), int8(0)]

var private c2da_str_132 : array<int8> = [int8(107), int8(101), int8(121), int8(95), int8(109), int8(101), int8(110), int8(117), int8(95), int8(100), int8(111), int8(119), int8(110), int8(0)]

var private c2da_str_133 : array<int8> = [int8(107), int8(101), int8(121), int8(95), int8(109), int8(101), int8(110), int8(117), int8(95), int8(108), int8(101), int8(102), int8(116), int8(0)]

var private c2da_str_134 : array<int8> = [int8(107), int8(101), int8(121), int8(95), int8(109), int8(101), int8(110), int8(117), int8(95), int8(114), int8(105), int8(103), int8(104), int8(116), int8(0)]

var private c2da_str_135 : array<int8> = [int8(107), int8(101), int8(121), int8(95), int8(109), int8(101), int8(110), int8(117), int8(95), int8(98), int8(97), int8(99), int8(107), int8(0)]

var private c2da_str_136 : array<int8> = [int8(107), int8(101), int8(121), int8(95), int8(109), int8(101), int8(110), int8(117), int8(95), int8(102), int8(111), int8(114), int8(119), int8(97), int8(114), int8(100), int8(0)]

var private c2da_str_137 : array<int8> = [int8(107), int8(101), int8(121), int8(95), int8(109), int8(101), int8(110), int8(117), int8(95), int8(99), int8(111), int8(110), int8(102), int8(105), int8(114), int8(109), int8(0)]

var private c2da_str_138 : array<int8> = [int8(107), int8(101), int8(121), int8(95), int8(109), int8(101), int8(110), int8(117), int8(95), int8(97), int8(98), int8(111), int8(114), int8(116), int8(0)]

var private c2da_str_139 : array<int8> = [int8(107), int8(101), int8(121), int8(95), int8(109), int8(101), int8(110), int8(117), int8(95), int8(104), int8(101), int8(108), int8(112), int8(0)]

var private c2da_str_140 : array<int8> = [int8(107), int8(101), int8(121), int8(95), int8(109), int8(101), int8(110), int8(117), int8(95), int8(115), int8(97), int8(118), int8(101), int8(0)]

var private c2da_str_141 : array<int8> = [int8(107), int8(101), int8(121), int8(95), int8(109), int8(101), int8(110), int8(117), int8(95), int8(108), int8(111), int8(97), int8(100), int8(0)]

var private c2da_str_142 : array<int8> = [int8(107), int8(101), int8(121), int8(95), int8(109), int8(101), int8(110), int8(117), int8(95), int8(118), int8(111), int8(108), int8(117), int8(109), int8(101), int8(0)]

var private c2da_str_143 : array<int8> = [int8(107), int8(101), int8(121), int8(95), int8(109), int8(101), int8(110), int8(117), int8(95), int8(100), int8(101), int8(116), int8(97), int8(105), int8(108), int8(0)]

var private c2da_str_144 : array<int8> = [int8(107), int8(101), int8(121), int8(95), int8(109), int8(101), int8(110), int8(117), int8(95), int8(113), int8(115), int8(97), int8(118), int8(101), int8(0)]

var private c2da_str_145 : array<int8> = [int8(107), int8(101), int8(121), int8(95), int8(109), int8(101), int8(110), int8(117), int8(95), int8(101), int8(110), int8(100), int8(103), int8(97), int8(109), int8(101), int8(0)]

var private c2da_str_146 : array<int8> = [int8(107), int8(101), int8(121), int8(95), int8(109), int8(101), int8(110), int8(117), int8(95), int8(109), int8(101), int8(115), int8(115), int8(97), int8(103), int8(101), int8(115), int8(0)]

var private c2da_str_147 : array<int8> = [int8(107), int8(101), int8(121), int8(95), int8(109), int8(101), int8(110), int8(117), int8(95), int8(113), int8(108), int8(111), int8(97), int8(100), int8(0)]

var private c2da_str_148 : array<int8> = [int8(107), int8(101), int8(121), int8(95), int8(109), int8(101), int8(110), int8(117), int8(95), int8(113), int8(117), int8(105), int8(116), int8(0)]

var private c2da_str_149 : array<int8> = [int8(107), int8(101), int8(121), int8(95), int8(109), int8(101), int8(110), int8(117), int8(95), int8(103), int8(97), int8(109), int8(109), int8(97), int8(0)]

var private c2da_str_150 : array<int8> = [int8(107), int8(101), int8(121), int8(95), int8(115), int8(112), int8(121), int8(0)]

var private c2da_str_151 : array<int8> = [int8(107), int8(101), int8(121), int8(95), int8(109), int8(101), int8(110), int8(117), int8(95), int8(105), int8(110), int8(99), int8(115), int8(99), int8(114), int8(101), int8(101), int8(110), int8(0)]

var private c2da_str_152 : array<int8> = [int8(107), int8(101), int8(121), int8(95), int8(109), int8(101), int8(110), int8(117), int8(95), int8(100), int8(101), int8(99), int8(115), int8(99), int8(114), int8(101), int8(101), int8(110), int8(0)]

var private c2da_str_153 : array<int8> = [int8(107), int8(101), int8(121), int8(95), int8(109), int8(101), int8(110), int8(117), int8(95), int8(115), int8(99), int8(114), int8(101), int8(101), int8(110), int8(115), int8(104), int8(111), int8(116), int8(0)]

var private c2da_str_154 : array<int8> = [int8(107), int8(101), int8(121), int8(95), int8(109), int8(97), int8(112), int8(95), int8(116), int8(111), int8(103), int8(103), int8(108), int8(101), int8(0)]

var private c2da_str_155 : array<int8> = [int8(107), int8(101), int8(121), int8(95), int8(109), int8(97), int8(112), int8(95), int8(110), int8(111), int8(114), int8(116), int8(104), int8(0)]

var private c2da_str_156 : array<int8> = [int8(107), int8(101), int8(121), int8(95), int8(109), int8(97), int8(112), int8(95), int8(115), int8(111), int8(117), int8(116), int8(104), int8(0)]

var private c2da_str_157 : array<int8> = [int8(107), int8(101), int8(121), int8(95), int8(109), int8(97), int8(112), int8(95), int8(101), int8(97), int8(115), int8(116), int8(0)]

var private c2da_str_158 : array<int8> = [int8(107), int8(101), int8(121), int8(95), int8(109), int8(97), int8(112), int8(95), int8(119), int8(101), int8(115), int8(116), int8(0)]

var private c2da_str_159 : array<int8> = [int8(107), int8(101), int8(121), int8(95), int8(109), int8(97), int8(112), int8(95), int8(122), int8(111), int8(111), int8(109), int8(105), int8(110), int8(0)]

var private c2da_str_160 : array<int8> = [int8(107), int8(101), int8(121), int8(95), int8(109), int8(97), int8(112), int8(95), int8(122), int8(111), int8(111), int8(109), int8(111), int8(117), int8(116), int8(0)]

var private c2da_str_161 : array<int8> = [int8(107), int8(101), int8(121), int8(95), int8(109), int8(97), int8(112), int8(95), int8(109), int8(97), int8(120), int8(122), int8(111), int8(111), int8(109), int8(0)]

var private c2da_str_162 : array<int8> = [int8(107), int8(101), int8(121), int8(95), int8(109), int8(97), int8(112), int8(95), int8(102), int8(111), int8(108), int8(108), int8(111), int8(119), int8(0)]

var private c2da_str_163 : array<int8> = [int8(107), int8(101), int8(121), int8(95), int8(109), int8(97), int8(112), int8(95), int8(103), int8(114), int8(105), int8(100), int8(0)]

var private c2da_str_164 : array<int8> = [int8(107), int8(101), int8(121), int8(95), int8(109), int8(97), int8(112), int8(95), int8(109), int8(97), int8(114), int8(107), int8(0)]

var private c2da_str_165 : array<int8> = [int8(107), int8(101), int8(121), int8(95), int8(109), int8(97), int8(112), int8(95), int8(99), int8(108), int8(101), int8(97), int8(114), int8(109), int8(97), int8(114), int8(107), int8(0)]

var private c2da_str_166 : array<int8> = [int8(107), int8(101), int8(121), int8(95), int8(119), int8(101), int8(97), int8(112), int8(111), int8(110), int8(49), int8(0)]

var private c2da_str_167 : array<int8> = [int8(107), int8(101), int8(121), int8(95), int8(119), int8(101), int8(97), int8(112), int8(111), int8(110), int8(50), int8(0)]

var private c2da_str_168 : array<int8> = [int8(107), int8(101), int8(121), int8(95), int8(119), int8(101), int8(97), int8(112), int8(111), int8(110), int8(51), int8(0)]

var private c2da_str_169 : array<int8> = [int8(107), int8(101), int8(121), int8(95), int8(119), int8(101), int8(97), int8(112), int8(111), int8(110), int8(52), int8(0)]

var private c2da_str_170 : array<int8> = [int8(107), int8(101), int8(121), int8(95), int8(119), int8(101), int8(97), int8(112), int8(111), int8(110), int8(53), int8(0)]

var private c2da_str_171 : array<int8> = [int8(107), int8(101), int8(121), int8(95), int8(119), int8(101), int8(97), int8(112), int8(111), int8(110), int8(54), int8(0)]

var private c2da_str_172 : array<int8> = [int8(107), int8(101), int8(121), int8(95), int8(119), int8(101), int8(97), int8(112), int8(111), int8(110), int8(55), int8(0)]

var private c2da_str_173 : array<int8> = [int8(107), int8(101), int8(121), int8(95), int8(119), int8(101), int8(97), int8(112), int8(111), int8(110), int8(56), int8(0)]

var private c2da_str_174 : array<int8> = [int8(107), int8(101), int8(121), int8(95), int8(112), int8(114), int8(101), int8(118), int8(119), int8(101), int8(97), int8(112), int8(111), int8(110), int8(0)]

var private c2da_str_175 : array<int8> = [int8(107), int8(101), int8(121), int8(95), int8(110), int8(101), int8(120), int8(116), int8(119), int8(101), int8(97), int8(112), int8(111), int8(110), int8(0)]

var private c2da_str_176 : array<int8> = [int8(107), int8(101), int8(121), int8(95), int8(97), int8(114), int8(116), int8(105), int8(95), int8(97), int8(108), int8(108), int8(0)]

var private c2da_str_177 : array<int8> = [int8(107), int8(101), int8(121), int8(95), int8(97), int8(114), int8(116), int8(105), int8(95), int8(104), int8(101), int8(97), int8(108), int8(116), int8(104), int8(0)]

var private c2da_str_178 : array<int8> = [int8(107), int8(101), int8(121), int8(95), int8(97), int8(114), int8(116), int8(105), int8(95), int8(112), int8(111), int8(105), int8(115), int8(111), int8(110), int8(98), int8(97), int8(103), int8(0)]

var private c2da_str_179 : array<int8> = [int8(107), int8(101), int8(121), int8(95), int8(97), int8(114), int8(116), int8(105), int8(95), int8(98), int8(108), int8(97), int8(115), int8(116), int8(114), int8(97), int8(100), int8(105), int8(117), int8(115), int8(0)]

var private c2da_str_180 : array<int8> = [int8(107), int8(101), int8(121), int8(95), int8(97), int8(114), int8(116), int8(105), int8(95), int8(116), int8(101), int8(108), int8(101), int8(112), int8(111), int8(114), int8(116), int8(0)]

var private c2da_str_181 : array<int8> = [int8(107), int8(101), int8(121), int8(95), int8(97), int8(114), int8(116), int8(105), int8(95), int8(116), int8(101), int8(108), int8(101), int8(112), int8(111), int8(114), int8(116), int8(111), int8(116), int8(104), int8(101), int8(114), int8(0)]

var private c2da_str_182 : array<int8> = [int8(107), int8(101), int8(121), int8(95), int8(97), int8(114), int8(116), int8(105), int8(95), int8(101), int8(103), int8(103), int8(0)]

var private c2da_str_183 : array<int8> = [int8(107), int8(101), int8(121), int8(95), int8(97), int8(114), int8(116), int8(105), int8(95), int8(105), int8(110), int8(118), int8(117), int8(108), int8(110), int8(101), int8(114), int8(97), int8(98), int8(105), int8(108), int8(105), int8(116), int8(121), int8(0)]

var private c2da_str_184 : array<int8> = [int8(107), int8(101), int8(121), int8(95), int8(109), int8(101), int8(115), int8(115), int8(97), int8(103), int8(101), int8(95), int8(114), int8(101), int8(102), int8(114), int8(101), int8(115), int8(104), int8(0)]

var private c2da_str_185 : array<int8> = [int8(107), int8(101), int8(121), int8(95), int8(100), int8(101), int8(109), int8(111), int8(95), int8(113), int8(117), int8(105), int8(116), int8(0)]

var private c2da_str_186 : array<int8> = [int8(107), int8(101), int8(121), int8(95), int8(109), int8(117), int8(108), int8(116), int8(105), int8(95), int8(109), int8(115), int8(103), int8(0)]

var private c2da_str_187 : array<int8> = [int8(107), int8(101), int8(121), int8(95), int8(109), int8(117), int8(108), int8(116), int8(105), int8(95), int8(109), int8(115), int8(103), int8(112), int8(108), int8(97), int8(121), int8(101), int8(114), int8(49), int8(0)]

var private c2da_str_188 : array<int8> = [int8(107), int8(101), int8(121), int8(95), int8(109), int8(117), int8(108), int8(116), int8(105), int8(95), int8(109), int8(115), int8(103), int8(112), int8(108), int8(97), int8(121), int8(101), int8(114), int8(50), int8(0)]

var private c2da_str_189 : array<int8> = [int8(107), int8(101), int8(121), int8(95), int8(109), int8(117), int8(108), int8(116), int8(105), int8(95), int8(109), int8(115), int8(103), int8(112), int8(108), int8(97), int8(121), int8(101), int8(114), int8(51), int8(0)]

var private c2da_str_190 : array<int8> = [int8(107), int8(101), int8(121), int8(95), int8(109), int8(117), int8(108), int8(116), int8(105), int8(95), int8(109), int8(115), int8(103), int8(112), int8(108), int8(97), int8(121), int8(101), int8(114), int8(52), int8(0)]

var private c2da_str_191 : array<int8> = [int8(107), int8(101), int8(121), int8(95), int8(109), int8(117), int8(108), int8(116), int8(105), int8(95), int8(109), int8(115), int8(103), int8(112), int8(108), int8(97), int8(121), int8(101), int8(114), int8(53), int8(0)]

var private c2da_str_192 : array<int8> = [int8(107), int8(101), int8(121), int8(95), int8(109), int8(117), int8(108), int8(116), int8(105), int8(95), int8(109), int8(115), int8(103), int8(112), int8(108), int8(97), int8(121), int8(101), int8(114), int8(54), int8(0)]

var private c2da_str_193 : array<int8> = [int8(107), int8(101), int8(121), int8(95), int8(109), int8(117), int8(108), int8(116), int8(105), int8(95), int8(109), int8(115), int8(103), int8(112), int8(108), int8(97), int8(121), int8(101), int8(114), int8(55), int8(0)]

var private c2da_str_194 : array<int8> = [int8(107), int8(101), int8(121), int8(95), int8(109), int8(117), int8(108), int8(116), int8(105), int8(95), int8(109), int8(115), int8(103), int8(112), int8(108), int8(97), int8(121), int8(101), int8(114), int8(56), int8(0)]

var private c2da_str_195 : array<int8> = [int8(37), int8(120), int8(0)]

var private c2da_str_196 : array<int8> = [int8(37), int8(105), int8(0)]

var private c2da_str_197 : array<int8> = [int8(45), int8(99), int8(111), int8(110), int8(102), int8(105), int8(103), int8(0)]

var private c2da_str_198 : array<int8> = [int8(9), int8(100), int8(101), int8(102), int8(97), int8(117), int8(108), int8(116), int8(32), int8(102), int8(105), int8(108), int8(101), int8(58), int8(32), int8(37), int8(115), int8(10), int8(0)]

var private c2da_str_199 : array<int8> = [int8(115), int8(97), int8(118), int8(105), int8(110), int8(103), int8(32), int8(99), int8(111), int8(110), int8(102), int8(105), int8(103), int8(32), int8(105), int8(110), int8(32), int8(37), int8(115), int8(10), int8(0)]

var private c2da_str_200 : array<int8> = [int8(45), int8(101), int8(120), int8(116), int8(114), int8(97), int8(99), int8(111), int8(110), int8(102), int8(105), int8(103), int8(0)]

var private c2da_str_201 : array<int8> = [int8(32), int8(32), int8(32), int8(32), int8(32), int8(32), int8(32), int8(32), int8(101), int8(120), int8(116), int8(114), int8(97), int8(32), int8(99), int8(111), int8(110), int8(102), int8(105), int8(103), int8(117), int8(114), int8(97), int8(116), int8(105), int8(111), int8(110), int8(32), int8(102), int8(105), int8(108), int8(101), int8(58), int8(32), int8(37), int8(115), int8(10), int8(0)]

var private c2da_str_202 : array<int8> = [int8(85), int8(110), int8(107), int8(110), int8(111), int8(119), int8(110), int8(32), int8(99), int8(111), int8(110), int8(102), int8(105), int8(103), int8(117), int8(114), int8(97), int8(116), int8(105), int8(111), int8(110), int8(32), int8(118), int8(97), int8(114), int8(105), int8(97), int8(98), int8(108), int8(101), int8(58), int8(32), int8(39), int8(37), int8(115), int8(39), int8(0)]

var private c2da_str_203 : array<int8> = [int8(0)]

var private c2da_str_204 : array<int8> = [int8(85), int8(115), int8(105), int8(110), int8(103), int8(32), int8(37), int8(115), int8(32), int8(102), int8(111), int8(114), int8(32), int8(99), int8(111), int8(110), int8(102), int8(105), int8(103), int8(117), int8(114), int8(97), int8(116), int8(105), int8(111), int8(110), int8(32), int8(97), int8(110), int8(100), int8(32), int8(115), int8(97), int8(118), int8(101), int8(115), int8(10), int8(0)]

var private c2da_str_205 : array<int8> = [int8(47), int8(0)]

var private c2da_str_206 : array<int8> = [int8(46), int8(115), int8(97), int8(118), int8(101), int8(103), int8(97), int8(109), int8(101), int8(47), int8(0)]

var private c2da_str_207 : array<int8> = [int8(85), int8(115), int8(105), int8(110), int8(103), int8(32), int8(37), int8(115), int8(32), int8(102), int8(111), int8(114), int8(32), int8(115), int8(97), int8(118), int8(101), int8(103), int8(97), int8(109), int8(101), int8(115), int8(10), int8(0)]

[sideeffects]
def private c2da___bswap_16(var c2da___bsx : uint16) : uint16 {
    return uint16(int(c2da___bsx) >> 8 & 255 | (int(c2da___bsx) & 255) << 8)
}
[sideeffects]
def private c2da___bswap_32(var c2da___bsx_0 : uint) : uint {
    return (c2da___bsx_0 & 0xff000000u) >> 24u | (c2da___bsx_0 & 0xff0000u) >> 8u | (c2da___bsx_0 & 0xff00u) << 8u | (c2da___bsx_0 & 0xffu) << 24u
}
[sideeffects]
def private c2da___bswap_64(var c2da___bsx_1 : uint64) : uint64 {
    return (c2da___bsx_1 & 0xff00000000000000ul) >> 56ul | (c2da___bsx_1 & 0xff000000000000ul) >> 40ul | (c2da___bsx_1 & 0xff0000000000ul) >> 24ul | (c2da___bsx_1 & 0xff00000000ul) >> 8ul | (c2da___bsx_1 & 0xff000000ul) << 8ul | (c2da___bsx_1 & 0xff0000ul) << 24ul | (c2da___bsx_1 & 0xff00ul) << 40ul | (c2da___bsx_1 & 0xfful) << 56ul
}
[sideeffects]
def private c2da___uint16_identity(var c2da___x : uint16) : uint16 {
    return c2da___x
}
[sideeffects]
def private c2da___uint32_identity(var c2da___x_0 : uint) : uint {
    return c2da___x_0
}
[sideeffects]
def private c2da___uint64_identity(var c2da___x_1 : uint64) : uint64 {
    return c2da___x_1
}
var configdir : int8?

var private default_main_config : int8?

var private default_extra_config : int8?

var private doom_defaults_list : default_t[76] = fixed_array<default_t>(default_t(name = unsafe(addr(c2da_str_0[0])), location = null, type_0 = unsafe(reinterpret<default_type_t>(0u)), untranslated = 0, original_translated = 0, bound = 0u), default_t(name = unsafe(addr(c2da_str_1[0])), location = null, type_0 = unsafe(reinterpret<default_type_t>(0u)), untranslated = 0, original_translated = 0, bound = 0u), default_t(name = unsafe(addr(c2da_str_2[0])), location = null, type_0 = unsafe(reinterpret<default_type_t>(0u)), untranslated = 0, original_translated = 0, bound = 0u), default_t(name = unsafe(addr(c2da_str_3[0])), location = null, type_0 = unsafe(reinterpret<default_type_t>(0u)), untranslated = 0, original_translated = 0, bound = 0u), default_t(name = unsafe(addr(c2da_str_4[0])), location = null, type_0 = unsafe(reinterpret<default_type_t>(0u)), untranslated = 0, original_translated = 0, bound = 0u), default_t(name = unsafe(addr(c2da_str_5[0])), location = null, type_0 = unsafe(reinterpret<default_type_t>(0u)), untranslated = 0, original_translated = 0, bound = 0u), default_t(name = unsafe(addr(c2da_str_6[0])), location = null, type_0 = unsafe(reinterpret<default_type_t>(4u)), untranslated = 0, original_translated = 0, bound = 0u), default_t(name = unsafe(addr(c2da_str_7[0])), location = null, type_0 = unsafe(reinterpret<default_type_t>(4u)), untranslated = 0, original_translated = 0, bound = 0u), default_t(name = unsafe(addr(c2da_str_8[0])), location = null, type_0 = unsafe(reinterpret<default_type_t>(4u)), untranslated = 0, original_translated = 0, bound = 0u), default_t(name = unsafe(addr(c2da_str_9[0])), location = null, type_0 = unsafe(reinterpret<default_type_t>(4u)), untranslated = 0, original_translated = 0, bound = 0u), default_t(name = unsafe(addr(c2da_str_10[0])), location = null, type_0 = unsafe(reinterpret<default_type_t>(4u)), untranslated = 0, original_translated = 0, bound = 0u), default_t(name = unsafe(addr(c2da_str_11[0])), location = null, type_0 = unsafe(reinterpret<default_type_t>(4u)), untranslated = 0, original_translated = 0, bound = 0u), default_t(name = unsafe(addr(c2da_str_12[0])), location = null, type_0 = unsafe(reinterpret<default_type_t>(4u)), untranslated = 0, original_translated = 0, bound = 0u), default_t(name = unsafe(addr(c2da_str_13[0])), location = null, type_0 = unsafe(reinterpret<default_type_t>(4u)), untranslated = 0, original_translated = 0, bound = 0u), default_t(name = unsafe(addr(c2da_str_14[0])), location = null, type_0 = unsafe(reinterpret<default_type_t>(4u)), untranslated = 0, original_translated = 0, bound = 0u), default_t(name = unsafe(addr(c2da_str_15[0])), location = null, type_0 = unsafe(reinterpret<default_type_t>(4u)), untranslated = 0, original_translated = 0, bound = 0u), default_t(name = unsafe(addr(c2da_str_16[0])), location = null, type_0 = unsafe(reinterpret<default_type_t>(4u)), untranslated = 0, original_translated = 0, bound = 0u), default_t(name = unsafe(addr(c2da_str_17[0])), location = null, type_0 = unsafe(reinterpret<default_type_t>(4u)), untranslated = 0, original_translated = 0, bound = 0u), default_t(name = unsafe(addr(c2da_str_18[0])), location = null, type_0 = unsafe(reinterpret<default_type_t>(4u)), untranslated = 0, original_translated = 0, bound = 0u), default_t(name = unsafe(addr(c2da_str_19[0])), location = null, type_0 = unsafe(reinterpret<default_type_t>(4u)), untranslated = 0, original_translated = 0, bound = 0u), default_t(name = unsafe(addr(c2da_str_20[0])), location = null, type_0 = unsafe(reinterpret<default_type_t>(4u)), untranslated = 0, original_translated = 0, bound = 0u), default_t(name = unsafe(addr(c2da_str_21[0])), location = null, type_0 = unsafe(reinterpret<default_type_t>(4u)), untranslated = 0, original_translated = 0, bound = 0u), default_t(name = unsafe(addr(c2da_str_22[0])), location = null, type_0 = unsafe(reinterpret<default_type_t>(4u)), untranslated = 0, original_translated = 0, bound = 0u), default_t(name = unsafe(addr(c2da_str_23[0])), location = null, type_0 = unsafe(reinterpret<default_type_t>(4u)), untranslated = 0, original_translated = 0, bound = 0u), default_t(name = unsafe(addr(c2da_str_24[0])), location = null, type_0 = unsafe(reinterpret<default_type_t>(4u)), untranslated = 0, original_translated = 0, bound = 0u), default_t(name = unsafe(addr(c2da_str_25[0])), location = null, type_0 = unsafe(reinterpret<default_type_t>(4u)), untranslated = 0, original_translated = 0, bound = 0u), default_t(name = unsafe(addr(c2da_str_26[0])), location = null, type_0 = unsafe(reinterpret<default_type_t>(4u)), untranslated = 0, original_translated = 0, bound = 0u), default_t(name = unsafe(addr(c2da_str_27[0])), location = null, type_0 = unsafe(reinterpret<default_type_t>(4u)), untranslated = 0, original_translated = 0, bound = 0u), default_t(name = unsafe(addr(c2da_str_28[0])), location = null, type_0 = unsafe(reinterpret<default_type_t>(4u)), untranslated = 0, original_translated = 0, bound = 0u), default_t(name = unsafe(addr(c2da_str_29[0])), location = null, type_0 = unsafe(reinterpret<default_type_t>(4u)), untranslated = 0, original_translated = 0, bound = 0u), default_t(name = unsafe(addr(c2da_str_30[0])), location = null, type_0 = unsafe(reinterpret<default_type_t>(4u)), untranslated = 0, original_translated = 0, bound = 0u), default_t(name = unsafe(addr(c2da_str_31[0])), location = null, type_0 = unsafe(reinterpret<default_type_t>(4u)), untranslated = 0, original_translated = 0, bound = 0u), default_t(name = unsafe(addr(c2da_str_32[0])), location = null, type_0 = unsafe(reinterpret<default_type_t>(4u)), untranslated = 0, original_translated = 0, bound = 0u), default_t(name = unsafe(addr(c2da_str_33[0])), location = null, type_0 = unsafe(reinterpret<default_type_t>(4u)), untranslated = 0, original_translated = 0, bound = 0u), default_t(name = unsafe(addr(c2da_str_34[0])), location = null, type_0 = unsafe(reinterpret<default_type_t>(4u)), untranslated = 0, original_translated = 0, bound = 0u), default_t(name = unsafe(addr(c2da_str_35[0])), location = null, type_0 = unsafe(reinterpret<default_type_t>(4u)), untranslated = 0, original_translated = 0, bound = 0u), default_t(name = unsafe(addr(c2da_str_36[0])), location = null, type_0 = unsafe(reinterpret<default_type_t>(4u)), untranslated = 0, original_translated = 0, bound = 0u), default_t(name = unsafe(addr(c2da_str_37[0])), location = null, type_0 = unsafe(reinterpret<default_type_t>(4u)), untranslated = 0, original_translated = 0, bound = 0u), default_t(name = unsafe(addr(c2da_str_38[0])), location = null, type_0 = unsafe(reinterpret<default_type_t>(4u)), untranslated = 0, original_translated = 0, bound = 0u), default_t(name = unsafe(addr(c2da_str_39[0])), location = null, type_0 = unsafe(reinterpret<default_type_t>(0u)), untranslated = 0, original_translated = 0, bound = 0u), default_t(name = unsafe(addr(c2da_str_40[0])), location = null, type_0 = unsafe(reinterpret<default_type_t>(0u)), untranslated = 0, original_translated = 0, bound = 0u), default_t(name = unsafe(addr(c2da_str_41[0])), location = null, type_0 = unsafe(reinterpret<default_type_t>(0u)), untranslated = 0, original_translated = 0, bound = 0u), default_t(name = unsafe(addr(c2da_str_42[0])), location = null, type_0 = unsafe(reinterpret<default_type_t>(0u)), untranslated = 0, original_translated = 0, bound = 0u), default_t(name = unsafe(addr(c2da_str_43[0])), location = null, type_0 = unsafe(reinterpret<default_type_t>(0u)), untranslated = 0, original_translated = 0, bound = 0u), default_t(name = unsafe(addr(c2da_str_44[0])), location = null, type_0 = unsafe(reinterpret<default_type_t>(0u)), untranslated = 0, original_translated = 0, bound = 0u), default_t(name = unsafe(addr(c2da_str_45[0])), location = null, type_0 = unsafe(reinterpret<default_type_t>(0u)), untranslated = 0, original_translated = 0, bound = 0u), default_t(name = unsafe(addr(c2da_str_46[0])), location = null, type_0 = unsafe(reinterpret<default_type_t>(0u)), untranslated = 0, original_translated = 0, bound = 0u), default_t(name = unsafe(addr(c2da_str_47[0])), location = null, type_0 = unsafe(reinterpret<default_type_t>(0u)), untranslated = 0, original_translated = 0, bound = 0u), default_t(name = unsafe(addr(c2da_str_48[0])), location = null, type_0 = unsafe(reinterpret<default_type_t>(0u)), untranslated = 0, original_translated = 0, bound = 0u), default_t(name = unsafe(addr(c2da_str_49[0])), location = null, type_0 = unsafe(reinterpret<default_type_t>(0u)), untranslated = 0, original_translated = 0, bound = 0u), default_t(name = unsafe(addr(c2da_str_50[0])), location = null, type_0 = unsafe(reinterpret<default_type_t>(0u)), untranslated = 0, original_translated = 0, bound = 0u), default_t(name = unsafe(addr(c2da_str_51[0])), location = null, type_0 = unsafe(reinterpret<default_type_t>(0u)), untranslated = 0, original_translated = 0, bound = 0u), default_t(name = unsafe(addr(c2da_str_52[0])), location = null, type_0 = unsafe(reinterpret<default_type_t>(0u)), untranslated = 0, original_translated = 0, bound = 0u), default_t(name = unsafe(addr(c2da_str_53[0])), location = null, type_0 = unsafe(reinterpret<default_type_t>(0u)), untranslated = 0, original_translated = 0, bound = 0u), default_t(name = unsafe(addr(c2da_str_54[0])), location = null, type_0 = unsafe(reinterpret<default_type_t>(0u)), untranslated = 0, original_translated = 0, bound = 0u), default_t(name = unsafe(addr(c2da_str_55[0])), location = null, type_0 = unsafe(reinterpret<default_type_t>(0u)), untranslated = 0, original_translated = 0, bound = 0u), default_t(name = unsafe(addr(c2da_str_56[0])), location = null, type_0 = unsafe(reinterpret<default_type_t>(0u)), untranslated = 0, original_translated = 0, bound = 0u), default_t(name = unsafe(addr(c2da_str_57[0])), location = null, type_0 = unsafe(reinterpret<default_type_t>(0u)), untranslated = 0, original_translated = 0, bound = 0u), default_t(name = unsafe(addr(c2da_str_58[0])), location = null, type_0 = unsafe(reinterpret<default_type_t>(0u)), untranslated = 0, original_translated = 0, bound = 0u), default_t(name = unsafe(addr(c2da_str_59[0])), location = null, type_0 = unsafe(reinterpret<default_type_t>(0u)), untranslated = 0, original_translated = 0, bound = 0u), default_t(name = unsafe(addr(c2da_str_60[0])), location = null, type_0 = unsafe(reinterpret<default_type_t>(0u)), untranslated = 0, original_translated = 0, bound = 0u), default_t(name = unsafe(addr(c2da_str_61[0])), location = null, type_0 = unsafe(reinterpret<default_type_t>(2u)), untranslated = 0, original_translated = 0, bound = 0u), default_t(name = unsafe(addr(c2da_str_62[0])), location = null, type_0 = unsafe(reinterpret<default_type_t>(0u)), untranslated = 0, original_translated = 0, bound = 0u), default_t(name = unsafe(addr(c2da_str_63[0])), location = null, type_0 = unsafe(reinterpret<default_type_t>(2u)), untranslated = 0, original_translated = 0, bound = 0u), default_t(name = unsafe(addr(c2da_str_64[0])), location = null, type_0 = unsafe(reinterpret<default_type_t>(2u)), untranslated = 0, original_translated = 0, bound = 0u), default_t(name = unsafe(addr(c2da_str_65[0])), location = null, type_0 = unsafe(reinterpret<default_type_t>(2u)), untranslated = 0, original_translated = 0, bound = 0u), default_t(name = unsafe(addr(c2da_str_66[0])), location = null, type_0 = unsafe(reinterpret<default_type_t>(2u)), untranslated = 0, original_translated = 0, bound = 0u), default_t(name = unsafe(addr(c2da_str_67[0])), location = null, type_0 = unsafe(reinterpret<default_type_t>(2u)), untranslated = 0, original_translated = 0, bound = 0u), default_t(name = unsafe(addr(c2da_str_68[0])), location = null, type_0 = unsafe(reinterpret<default_type_t>(2u)), untranslated = 0, original_translated = 0, bound = 0u), default_t(name = unsafe(addr(c2da_str_69[0])), location = null, type_0 = unsafe(reinterpret<default_type_t>(2u)), untranslated = 0, original_translated = 0, bound = 0u), default_t(name = unsafe(addr(c2da_str_70[0])), location = null, type_0 = unsafe(reinterpret<default_type_t>(2u)), untranslated = 0, original_translated = 0, bound = 0u), default_t(name = unsafe(addr(c2da_str_71[0])), location = null, type_0 = unsafe(reinterpret<default_type_t>(2u)), untranslated = 0, original_translated = 0, bound = 0u), default_t(name = unsafe(addr(c2da_str_72[0])), location = null, type_0 = unsafe(reinterpret<default_type_t>(2u)), untranslated = 0, original_translated = 0, bound = 0u), default_t(name = unsafe(addr(c2da_str_73[0])), location = null, type_0 = unsafe(reinterpret<default_type_t>(2u)), untranslated = 0, original_translated = 0, bound = 0u), default_t(name = unsafe(addr(c2da_str_74[0])), location = null, type_0 = unsafe(reinterpret<default_type_t>(2u)), untranslated = 0, original_translated = 0, bound = 0u), default_t(name = unsafe(addr(c2da_str_75[0])), location = null, type_0 = unsafe(reinterpret<default_type_t>(0u)), untranslated = 0, original_translated = 0, bound = 0u))

var private doom_defaults : default_collection_t = default_collection_t(defaults = unsafe(addr(doom_defaults_list[0])), numdefaults = int(2432ul / 32ul), filename = null)

var private extra_defaults_list : default_t[119] = fixed_array<default_t>(default_t(name = unsafe(addr(c2da_str_76[0])), location = null, type_0 = unsafe(reinterpret<default_type_t>(0u)), untranslated = 0, original_translated = 0, bound = 0u), default_t(name = unsafe(addr(c2da_str_77[0])), location = null, type_0 = unsafe(reinterpret<default_type_t>(0u)), untranslated = 0, original_translated = 0, bound = 0u), default_t(name = unsafe(addr(c2da_str_78[0])), location = null, type_0 = unsafe(reinterpret<default_type_t>(0u)), untranslated = 0, original_translated = 0, bound = 0u), default_t(name = unsafe(addr(c2da_str_79[0])), location = null, type_0 = unsafe(reinterpret<default_type_t>(0u)), untranslated = 0, original_translated = 0, bound = 0u), default_t(name = unsafe(addr(c2da_str_80[0])), location = null, type_0 = unsafe(reinterpret<default_type_t>(0u)), untranslated = 0, original_translated = 0, bound = 0u), default_t(name = unsafe(addr(c2da_str_81[0])), location = null, type_0 = unsafe(reinterpret<default_type_t>(0u)), untranslated = 0, original_translated = 0, bound = 0u), default_t(name = unsafe(addr(c2da_str_82[0])), location = null, type_0 = unsafe(reinterpret<default_type_t>(0u)), untranslated = 0, original_translated = 0, bound = 0u), default_t(name = unsafe(addr(c2da_str_83[0])), location = null, type_0 = unsafe(reinterpret<default_type_t>(0u)), untranslated = 0, original_translated = 0, bound = 0u), default_t(name = unsafe(addr(c2da_str_84[0])), location = null, type_0 = unsafe(reinterpret<default_type_t>(0u)), untranslated = 0, original_translated = 0, bound = 0u), default_t(name = unsafe(addr(c2da_str_85[0])), location = null, type_0 = unsafe(reinterpret<default_type_t>(0u)), untranslated = 0, original_translated = 0, bound = 0u), default_t(name = unsafe(addr(c2da_str_86[0])), location = null, type_0 = unsafe(reinterpret<default_type_t>(3u)), untranslated = 0, original_translated = 0, bound = 0u), default_t(name = unsafe(addr(c2da_str_87[0])), location = null, type_0 = unsafe(reinterpret<default_type_t>(0u)), untranslated = 0, original_translated = 0, bound = 0u), default_t(name = unsafe(addr(c2da_str_88[0])), location = null, type_0 = unsafe(reinterpret<default_type_t>(0u)), untranslated = 0, original_translated = 0, bound = 0u), default_t(name = unsafe(addr(c2da_str_89[0])), location = null, type_0 = unsafe(reinterpret<default_type_t>(0u)), untranslated = 0, original_translated = 0, bound = 0u), default_t(name = unsafe(addr(c2da_str_90[0])), location = null, type_0 = unsafe(reinterpret<default_type_t>(0u)), untranslated = 0, original_translated = 0, bound = 0u), default_t(name = unsafe(addr(c2da_str_91[0])), location = null, type_0 = unsafe(reinterpret<default_type_t>(2u)), untranslated = 0, original_translated = 0, bound = 0u), default_t(name = unsafe(addr(c2da_str_92[0])), location = null, type_0 = unsafe(reinterpret<default_type_t>(1u)), untranslated = 0, original_translated = 0, bound = 0u), default_t(name = unsafe(addr(c2da_str_93[0])), location = null, type_0 = unsafe(reinterpret<default_type_t>(0u)), untranslated = 0, original_translated = 0, bound = 0u), default_t(name = unsafe(addr(c2da_str_94[0])), location = null, type_0 = unsafe(reinterpret<default_type_t>(0u)), untranslated = 0, original_translated = 0, bound = 0u), default_t(name = unsafe(addr(c2da_str_95[0])), location = null, type_0 = unsafe(reinterpret<default_type_t>(0u)), untranslated = 0, original_translated = 0, bound = 0u), default_t(name = unsafe(addr(c2da_str_96[0])), location = null, type_0 = unsafe(reinterpret<default_type_t>(0u)), untranslated = 0, original_translated = 0, bound = 0u), default_t(name = unsafe(addr(c2da_str_97[0])), location = null, type_0 = unsafe(reinterpret<default_type_t>(0u)), untranslated = 0, original_translated = 0, bound = 0u), default_t(name = unsafe(addr(c2da_str_98[0])), location = null, type_0 = unsafe(reinterpret<default_type_t>(2u)), untranslated = 0, original_translated = 0, bound = 0u), default_t(name = unsafe(addr(c2da_str_99[0])), location = null, type_0 = unsafe(reinterpret<default_type_t>(2u)), untranslated = 0, original_translated = 0, bound = 0u), default_t(name = unsafe(addr(c2da_str_100[0])), location = null, type_0 = unsafe(reinterpret<default_type_t>(0u)), untranslated = 0, original_translated = 0, bound = 0u), default_t(name = unsafe(addr(c2da_str_101[0])), location = null, type_0 = unsafe(reinterpret<default_type_t>(0u)), untranslated = 0, original_translated = 0, bound = 0u), default_t(name = unsafe(addr(c2da_str_102[0])), location = null, type_0 = unsafe(reinterpret<default_type_t>(0u)), untranslated = 0, original_translated = 0, bound = 0u), default_t(name = unsafe(addr(c2da_str_103[0])), location = null, type_0 = unsafe(reinterpret<default_type_t>(0u)), untranslated = 0, original_translated = 0, bound = 0u), default_t(name = unsafe(addr(c2da_str_104[0])), location = null, type_0 = unsafe(reinterpret<default_type_t>(0u)), untranslated = 0, original_translated = 0, bound = 0u), default_t(name = unsafe(addr(c2da_str_105[0])), location = null, type_0 = unsafe(reinterpret<default_type_t>(0u)), untranslated = 0, original_translated = 0, bound = 0u), default_t(name = unsafe(addr(c2da_str_106[0])), location = null, type_0 = unsafe(reinterpret<default_type_t>(0u)), untranslated = 0, original_translated = 0, bound = 0u), default_t(name = unsafe(addr(c2da_str_107[0])), location = null, type_0 = unsafe(reinterpret<default_type_t>(0u)), untranslated = 0, original_translated = 0, bound = 0u), default_t(name = unsafe(addr(c2da_str_108[0])), location = null, type_0 = unsafe(reinterpret<default_type_t>(0u)), untranslated = 0, original_translated = 0, bound = 0u), default_t(name = unsafe(addr(c2da_str_109[0])), location = null, type_0 = unsafe(reinterpret<default_type_t>(0u)), untranslated = 0, original_translated = 0, bound = 0u), default_t(name = unsafe(addr(c2da_str_110[0])), location = null, type_0 = unsafe(reinterpret<default_type_t>(0u)), untranslated = 0, original_translated = 0, bound = 0u), default_t(name = unsafe(addr(c2da_str_111[0])), location = null, type_0 = unsafe(reinterpret<default_type_t>(0u)), untranslated = 0, original_translated = 0, bound = 0u), default_t(name = unsafe(addr(c2da_str_112[0])), location = null, type_0 = unsafe(reinterpret<default_type_t>(0u)), untranslated = 0, original_translated = 0, bound = 0u), default_t(name = unsafe(addr(c2da_str_113[0])), location = null, type_0 = unsafe(reinterpret<default_type_t>(0u)), untranslated = 0, original_translated = 0, bound = 0u), default_t(name = unsafe(addr(c2da_str_114[0])), location = null, type_0 = unsafe(reinterpret<default_type_t>(0u)), untranslated = 0, original_translated = 0, bound = 0u), default_t(name = unsafe(addr(c2da_str_115[0])), location = null, type_0 = unsafe(reinterpret<default_type_t>(0u)), untranslated = 0, original_translated = 0, bound = 0u), default_t(name = unsafe(addr(c2da_str_116[0])), location = null, type_0 = unsafe(reinterpret<default_type_t>(0u)), untranslated = 0, original_translated = 0, bound = 0u), default_t(name = unsafe(addr(c2da_str_117[0])), location = null, type_0 = unsafe(reinterpret<default_type_t>(0u)), untranslated = 0, original_translated = 0, bound = 0u), default_t(name = unsafe(addr(c2da_str_118[0])), location = null, type_0 = unsafe(reinterpret<default_type_t>(0u)), untranslated = 0, original_translated = 0, bound = 0u), default_t(name = unsafe(addr(c2da_str_119[0])), location = null, type_0 = unsafe(reinterpret<default_type_t>(0u)), untranslated = 0, original_translated = 0, bound = 0u), default_t(name = unsafe(addr(c2da_str_120[0])), location = null, type_0 = unsafe(reinterpret<default_type_t>(0u)), untranslated = 0, original_translated = 0, bound = 0u), default_t(name = unsafe(addr(c2da_str_121[0])), location = null, type_0 = unsafe(reinterpret<default_type_t>(0u)), untranslated = 0, original_translated = 0, bound = 0u), default_t(name = unsafe(addr(c2da_str_122[0])), location = null, type_0 = unsafe(reinterpret<default_type_t>(0u)), untranslated = 0, original_translated = 0, bound = 0u), default_t(name = unsafe(addr(c2da_str_123[0])), location = null, type_0 = unsafe(reinterpret<default_type_t>(0u)), untranslated = 0, original_translated = 0, bound = 0u), default_t(name = unsafe(addr(c2da_str_124[0])), location = null, type_0 = unsafe(reinterpret<default_type_t>(0u)), untranslated = 0, original_translated = 0, bound = 0u), default_t(name = unsafe(addr(c2da_str_125[0])), location = null, type_0 = unsafe(reinterpret<default_type_t>(0u)), untranslated = 0, original_translated = 0, bound = 0u), default_t(name = unsafe(addr(c2da_str_126[0])), location = null, type_0 = unsafe(reinterpret<default_type_t>(0u)), untranslated = 0, original_translated = 0, bound = 0u), default_t(name = unsafe(addr(c2da_str_127[0])), location = null, type_0 = unsafe(reinterpret<default_type_t>(0u)), untranslated = 0, original_translated = 0, bound = 0u), default_t(name = unsafe(addr(c2da_str_128[0])), location = null, type_0 = unsafe(reinterpret<default_type_t>(0u)), untranslated = 0, original_translated = 0, bound = 0u), default_t(name = unsafe(addr(c2da_str_129[0])), location = null, type_0 = unsafe(reinterpret<default_type_t>(4u)), untranslated = 0, original_translated = 0, bound = 0u), default_t(name = unsafe(addr(c2da_str_130[0])), location = null, type_0 = unsafe(reinterpret<default_type_t>(4u)), untranslated = 0, original_translated = 0, bound = 0u), default_t(name = unsafe(addr(c2da_str_131[0])), location = null, type_0 = unsafe(reinterpret<default_type_t>(4u)), untranslated = 0, original_translated = 0, bound = 0u), default_t(name = unsafe(addr(c2da_str_132[0])), location = null, type_0 = unsafe(reinterpret<default_type_t>(4u)), untranslated = 0, original_translated = 0, bound = 0u), default_t(name = unsafe(addr(c2da_str_133[0])), location = null, type_0 = unsafe(reinterpret<default_type_t>(4u)), untranslated = 0, original_translated = 0, bound = 0u), default_t(name = unsafe(addr(c2da_str_134[0])), location = null, type_0 = unsafe(reinterpret<default_type_t>(4u)), untranslated = 0, original_translated = 0, bound = 0u), default_t(name = unsafe(addr(c2da_str_135[0])), location = null, type_0 = unsafe(reinterpret<default_type_t>(4u)), untranslated = 0, original_translated = 0, bound = 0u), default_t(name = unsafe(addr(c2da_str_136[0])), location = null, type_0 = unsafe(reinterpret<default_type_t>(4u)), untranslated = 0, original_translated = 0, bound = 0u), default_t(name = unsafe(addr(c2da_str_137[0])), location = null, type_0 = unsafe(reinterpret<default_type_t>(4u)), untranslated = 0, original_translated = 0, bound = 0u), default_t(name = unsafe(addr(c2da_str_138[0])), location = null, type_0 = unsafe(reinterpret<default_type_t>(4u)), untranslated = 0, original_translated = 0, bound = 0u), default_t(name = unsafe(addr(c2da_str_139[0])), location = null, type_0 = unsafe(reinterpret<default_type_t>(4u)), untranslated = 0, original_translated = 0, bound = 0u), default_t(name = unsafe(addr(c2da_str_140[0])), location = null, type_0 = unsafe(reinterpret<default_type_t>(4u)), untranslated = 0, original_translated = 0, bound = 0u), default_t(name = unsafe(addr(c2da_str_141[0])), location = null, type_0 = unsafe(reinterpret<default_type_t>(4u)), untranslated = 0, original_translated = 0, bound = 0u), default_t(name = unsafe(addr(c2da_str_142[0])), location = null, type_0 = unsafe(reinterpret<default_type_t>(4u)), untranslated = 0, original_translated = 0, bound = 0u), default_t(name = unsafe(addr(c2da_str_143[0])), location = null, type_0 = unsafe(reinterpret<default_type_t>(4u)), untranslated = 0, original_translated = 0, bound = 0u), default_t(name = unsafe(addr(c2da_str_144[0])), location = null, type_0 = unsafe(reinterpret<default_type_t>(4u)), untranslated = 0, original_translated = 0, bound = 0u), default_t(name = unsafe(addr(c2da_str_145[0])), location = null, type_0 = unsafe(reinterpret<default_type_t>(4u)), untranslated = 0, original_translated = 0, bound = 0u), default_t(name = unsafe(addr(c2da_str_146[0])), location = null, type_0 = unsafe(reinterpret<default_type_t>(4u)), untranslated = 0, original_translated = 0, bound = 0u), default_t(name = unsafe(addr(c2da_str_147[0])), location = null, type_0 = unsafe(reinterpret<default_type_t>(4u)), untranslated = 0, original_translated = 0, bound = 0u), default_t(name = unsafe(addr(c2da_str_148[0])), location = null, type_0 = unsafe(reinterpret<default_type_t>(4u)), untranslated = 0, original_translated = 0, bound = 0u), default_t(name = unsafe(addr(c2da_str_149[0])), location = null, type_0 = unsafe(reinterpret<default_type_t>(4u)), untranslated = 0, original_translated = 0, bound = 0u), default_t(name = unsafe(addr(c2da_str_150[0])), location = null, type_0 = unsafe(reinterpret<default_type_t>(4u)), untranslated = 0, original_translated = 0, bound = 0u), default_t(name = unsafe(addr(c2da_str_151[0])), location = null, type_0 = unsafe(reinterpret<default_type_t>(4u)), untranslated = 0, original_translated = 0, bound = 0u), default_t(name = unsafe(addr(c2da_str_152[0])), location = null, type_0 = unsafe(reinterpret<default_type_t>(4u)), untranslated = 0, original_translated = 0, bound = 0u), default_t(name = unsafe(addr(c2da_str_153[0])), location = null, type_0 = unsafe(reinterpret<default_type_t>(4u)), untranslated = 0, original_translated = 0, bound = 0u), default_t(name = unsafe(addr(c2da_str_154[0])), location = null, type_0 = unsafe(reinterpret<default_type_t>(4u)), untranslated = 0, original_translated = 0, bound = 0u), default_t(name = unsafe(addr(c2da_str_155[0])), location = null, type_0 = unsafe(reinterpret<default_type_t>(4u)), untranslated = 0, original_translated = 0, bound = 0u), default_t(name = unsafe(addr(c2da_str_156[0])), location = null, type_0 = unsafe(reinterpret<default_type_t>(4u)), untranslated = 0, original_translated = 0, bound = 0u), default_t(name = unsafe(addr(c2da_str_157[0])), location = null, type_0 = unsafe(reinterpret<default_type_t>(4u)), untranslated = 0, original_translated = 0, bound = 0u), default_t(name = unsafe(addr(c2da_str_158[0])), location = null, type_0 = unsafe(reinterpret<default_type_t>(4u)), untranslated = 0, original_translated = 0, bound = 0u), default_t(name = unsafe(addr(c2da_str_159[0])), location = null, type_0 = unsafe(reinterpret<default_type_t>(4u)), untranslated = 0, original_translated = 0, bound = 0u), default_t(name = unsafe(addr(c2da_str_160[0])), location = null, type_0 = unsafe(reinterpret<default_type_t>(4u)), untranslated = 0, original_translated = 0, bound = 0u), default_t(name = unsafe(addr(c2da_str_161[0])), location = null, type_0 = unsafe(reinterpret<default_type_t>(4u)), untranslated = 0, original_translated = 0, bound = 0u), default_t(name = unsafe(addr(c2da_str_162[0])), location = null, type_0 = unsafe(reinterpret<default_type_t>(4u)), untranslated = 0, original_translated = 0, bound = 0u), default_t(name = unsafe(addr(c2da_str_163[0])), location = null, type_0 = unsafe(reinterpret<default_type_t>(4u)), untranslated = 0, original_translated = 0, bound = 0u), default_t(name = unsafe(addr(c2da_str_164[0])), location = null, type_0 = unsafe(reinterpret<default_type_t>(4u)), untranslated = 0, original_translated = 0, bound = 0u), default_t(name = unsafe(addr(c2da_str_165[0])), location = null, type_0 = unsafe(reinterpret<default_type_t>(4u)), untranslated = 0, original_translated = 0, bound = 0u), default_t(name = unsafe(addr(c2da_str_166[0])), location = null, type_0 = unsafe(reinterpret<default_type_t>(4u)), untranslated = 0, original_translated = 0, bound = 0u), default_t(name = unsafe(addr(c2da_str_167[0])), location = null, type_0 = unsafe(reinterpret<default_type_t>(4u)), untranslated = 0, original_translated = 0, bound = 0u), default_t(name = unsafe(addr(c2da_str_168[0])), location = null, type_0 = unsafe(reinterpret<default_type_t>(4u)), untranslated = 0, original_translated = 0, bound = 0u), default_t(name = unsafe(addr(c2da_str_169[0])), location = null, type_0 = unsafe(reinterpret<default_type_t>(4u)), untranslated = 0, original_translated = 0, bound = 0u), default_t(name = unsafe(addr(c2da_str_170[0])), location = null, type_0 = unsafe(reinterpret<default_type_t>(4u)), untranslated = 0, original_translated = 0, bound = 0u), default_t(name = unsafe(addr(c2da_str_171[0])), location = null, type_0 = unsafe(reinterpret<default_type_t>(4u)), untranslated = 0, original_translated = 0, bound = 0u), default_t(name = unsafe(addr(c2da_str_172[0])), location = null, type_0 = unsafe(reinterpret<default_type_t>(4u)), untranslated = 0, original_translated = 0, bound = 0u), default_t(name = unsafe(addr(c2da_str_173[0])), location = null, type_0 = unsafe(reinterpret<default_type_t>(4u)), untranslated = 0, original_translated = 0, bound = 0u), default_t(name = unsafe(addr(c2da_str_174[0])), location = null, type_0 = unsafe(reinterpret<default_type_t>(4u)), untranslated = 0, original_translated = 0, bound = 0u), default_t(name = unsafe(addr(c2da_str_175[0])), location = null, type_0 = unsafe(reinterpret<default_type_t>(4u)), untranslated = 0, original_translated = 0, bound = 0u), default_t(name = unsafe(addr(c2da_str_176[0])), location = null, type_0 = unsafe(reinterpret<default_type_t>(4u)), untranslated = 0, original_translated = 0, bound = 0u), default_t(name = unsafe(addr(c2da_str_177[0])), location = null, type_0 = unsafe(reinterpret<default_type_t>(4u)), untranslated = 0, original_translated = 0, bound = 0u), default_t(name = unsafe(addr(c2da_str_178[0])), location = null, type_0 = unsafe(reinterpret<default_type_t>(4u)), untranslated = 0, original_translated = 0, bound = 0u), default_t(name = unsafe(addr(c2da_str_179[0])), location = null, type_0 = unsafe(reinterpret<default_type_t>(4u)), untranslated = 0, original_translated = 0, bound = 0u), default_t(name = unsafe(addr(c2da_str_180[0])), location = null, type_0 = unsafe(reinterpret<default_type_t>(4u)), untranslated = 0, original_translated = 0, bound = 0u), default_t(name = unsafe(addr(c2da_str_181[0])), location = null, type_0 = unsafe(reinterpret<default_type_t>(4u)), untranslated = 0, original_translated = 0, bound = 0u), default_t(name = unsafe(addr(c2da_str_182[0])), location = null, type_0 = unsafe(reinterpret<default_type_t>(4u)), untranslated = 0, original_translated = 0, bound = 0u), default_t(name = unsafe(addr(c2da_str_183[0])), location = null, type_0 = unsafe(reinterpret<default_type_t>(4u)), untranslated = 0, original_translated = 0, bound = 0u), default_t(name = unsafe(addr(c2da_str_184[0])), location = null, type_0 = unsafe(reinterpret<default_type_t>(4u)), untranslated = 0, original_translated = 0, bound = 0u), default_t(name = unsafe(addr(c2da_str_185[0])), location = null, type_0 = unsafe(reinterpret<default_type_t>(4u)), untranslated = 0, original_translated = 0, bound = 0u), default_t(name = unsafe(addr(c2da_str_186[0])), location = null, type_0 = unsafe(reinterpret<default_type_t>(4u)), untranslated = 0, original_translated = 0, bound = 0u), default_t(name = unsafe(addr(c2da_str_187[0])), location = null, type_0 = unsafe(reinterpret<default_type_t>(4u)), untranslated = 0, original_translated = 0, bound = 0u), default_t(name = unsafe(addr(c2da_str_188[0])), location = null, type_0 = unsafe(reinterpret<default_type_t>(4u)), untranslated = 0, original_translated = 0, bound = 0u), default_t(name = unsafe(addr(c2da_str_189[0])), location = null, type_0 = unsafe(reinterpret<default_type_t>(4u)), untranslated = 0, original_translated = 0, bound = 0u), default_t(name = unsafe(addr(c2da_str_190[0])), location = null, type_0 = unsafe(reinterpret<default_type_t>(4u)), untranslated = 0, original_translated = 0, bound = 0u), default_t(name = unsafe(addr(c2da_str_191[0])), location = null, type_0 = unsafe(reinterpret<default_type_t>(4u)), untranslated = 0, original_translated = 0, bound = 0u), default_t(name = unsafe(addr(c2da_str_192[0])), location = null, type_0 = unsafe(reinterpret<default_type_t>(4u)), untranslated = 0, original_translated = 0, bound = 0u), default_t(name = unsafe(addr(c2da_str_193[0])), location = null, type_0 = unsafe(reinterpret<default_type_t>(4u)), untranslated = 0, original_translated = 0, bound = 0u), default_t(name = unsafe(addr(c2da_str_194[0])), location = null, type_0 = unsafe(reinterpret<default_type_t>(4u)), untranslated = 0, original_translated = 0, bound = 0u))

var private extra_defaults : default_collection_t = default_collection_t(defaults = unsafe(addr(extra_defaults_list[0])), numdefaults = int(3808ul / 32ul), filename = null)

[sideeffects]
def private SearchCollection(var collection : default_collection_t?; var name : int8?) : default_t? {
    var i : int = 0
    while (i < collection.numdefaults) {
        if (c2da_std_strcmp(unsafe(reinterpret<uint64>(name)), unsafe(reinterpret<uint64>(unsafe(collection.defaults[i]).name))) == 0) {
            return unsafe(addr<default_t?>(unsafe(collection.defaults[i])))
        }
        i++
    }
    return unsafe(reinterpret<default_t?>(null))
}
var private scantokey : int[128] const = fixed_array<int>(0, 27, 49, 50, 51, 52, 53, 54, 55, 56, 57, 48, 45, 61, 127, 9, 113, 119, 101, 114, 116, 121, 117, 105, 111, 112, 91, 93, 13, 128 + 29, 97, 115, 100, 102, 103, 104, 106, 107, 108, 59, 39, 96, 128 + 54, 92, 122, 120, 99, 118, 98, 110, 109, 44, 46, 47, 128 + 54, 42, 128 + 56, 32, 128 + 58, 128 + 59, 128 + 60, 128 + 61, 128 + 62, 128 + 63, 128 + 64, 128 + 65, 128 + 66, 128 + 67, 128 + 68, 255, 128 + 70, 128 + 71, 173, 128 + 73, 45, 172, 53, 174, 43, 128 + 79, 175, 128 + 81, 128 + 82, 128 + 83, 0, 0, 0, 128 + 87, 128 + 88, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 128 + 89, 0)

[sideeffects]
def private SaveDefaultCollection(var collection_0 : default_collection_t?) {
    return
}
[sideeffects]
def private ParseIntParameter(var strparm : int8?) : int {
    var parm : int
    if (int(unsafe(strparm[0])) == 48 && int(unsafe(strparm[1])) == 120) {
        c2da_std_sscanf(unsafe(reinterpret<uint64>(unsafe(strparm + 2))), unsafe(reinterpret<uint64>(unsafe(addr(c2da_str_195[0])))), [C2daVaArg(tag = 3, i64 = 0, f64 = 0.0lf, raw = unsafe(reinterpret<uint64>(unsafe(addr(parm)))))])
    } else {
        c2da_std_sscanf(unsafe(reinterpret<uint64>(strparm)), unsafe(reinterpret<uint64>(unsafe(addr(c2da_str_196[0])))), [C2daVaArg(tag = 3, i64 = 0, f64 = 0.0lf, raw = unsafe(reinterpret<uint64>(unsafe(addr(parm)))))])
    }
    return parm
}
[sideeffects]
def private SetVariable(var def_0 : default_t?; var value : int8?) {
    var c2da_fresh0 : uint
    var intparm : int
    c2da_fresh0 = uint(def_0.type_0)
    if (c2da_fresh0 == 0x2u) {
        *unsafe(reinterpret<int8??>(def_0.location)) = unsafe(reinterpret<int8?>(unsafe(reinterpret<int8?>(c2da_std_strdup(unsafe(reinterpret<uint64>(value)))))))
    } elif (c2da_fresh0 == 0x0u || c2da_fresh0 == 0x1u) {
        *unsafe(reinterpret<int?>(def_0.location)) = ParseIntParameter(value)
    } elif (c2da_fresh0 == 0x4u) {
        intparm = ParseIntParameter(value)
        def_0.untranslated = intparm
        if (intparm >= 0 && intparm < 128) {
            intparm = scantokey[intparm]
        } else {
            intparm = 0
        }
        def_0.original_translated = intparm
        *unsafe(reinterpret<int?>(def_0.location)) = intparm
    } elif (c2da_fresh0 == 0x3u) {
        *unsafe(reinterpret<float?>(def_0.location)) = float(c2da_std_atof(unsafe(reinterpret<uint64>(value))))
    }
    return
}
[sideeffects]
def private LoadDefaultCollection(var collection_1 : default_collection_t?) {
    return
}
[export, sideeffects]
def M_SetConfigFilenames(var main_config : int8?; var extra_config : int8?) {
    default_main_config = unsafe(reinterpret<int8?>(main_config))
    default_extra_config = unsafe(reinterpret<int8?>(extra_config))
    return
}
[export, sideeffects]
def M_SaveDefaults() {
    SaveDefaultCollection(unsafe(addr<default_collection_t?>(doom_defaults)))
    SaveDefaultCollection(unsafe(addr<default_collection_t?>(extra_defaults)))
    return
}
[export, sideeffects]
def M_SaveDefaultsAlternate(var main_0 : int8?; var extra : int8?) {
    var orig_main : int8?
    var orig_extra : int8?
    orig_main = unsafe(reinterpret<int8?>(doom_defaults.filename))
    orig_extra = unsafe(reinterpret<int8?>(extra_defaults.filename))
    doom_defaults.filename = unsafe(reinterpret<int8?>(main_0))
    extra_defaults.filename = unsafe(reinterpret<int8?>(extra))
    M_SaveDefaults()
    doom_defaults.filename = unsafe(reinterpret<int8?>(orig_main))
    extra_defaults.filename = unsafe(reinterpret<int8?>(orig_extra))
    return
}
[export, sideeffects]
def M_LoadDefaults() {
    var i_0 : int = M_CheckParmWithArgs(unsafe(addr<int8?>(c2da_str_197[0])), 1)
    if (i_0 != 0) {
        doom_defaults.filename = unsafe(reinterpret<int8?>(unsafe(myargv[i_0 + 1])))
        c2da_std_fprintf(unsafe(reinterpret<uint64>(unsafe(reinterpret<_IO_FILE?>(c2da_std_stderr())))), unsafe(addr<int8 const?>(c2da_str_198[0])), [C2daVaArg(tag = 3, i64 = 0, f64 = 0.0lf, raw = unsafe(reinterpret<uint64>(doom_defaults.filename)))])
    } else {
        doom_defaults.filename = unsafe(reinterpret<int8?>(unsafe(reinterpret<int8?>(M_StringJoin(unsafe(reinterpret<int8 const?>(configdir)), [C2daVaArg(tag = 3, i64 = 0, f64 = 0.0lf, raw = unsafe(reinterpret<uint64>(default_main_config))), C2daVaArg(tag = 3, i64 = 0, f64 = 0.0lf, raw = unsafe(reinterpret<uint64>(null)))])))))
    }
    c2da_std_fprintf(unsafe(reinterpret<uint64>(unsafe(reinterpret<_IO_FILE?>(c2da_std_stderr())))), unsafe(addr<int8 const?>(c2da_str_199[0])), [C2daVaArg(tag = 3, i64 = 0, f64 = 0.0lf, raw = unsafe(reinterpret<uint64>(doom_defaults.filename)))])
    i_0 = M_CheckParmWithArgs(unsafe(addr<int8?>(c2da_str_200[0])), 1)
    if (i_0 != 0) {
        extra_defaults.filename = unsafe(reinterpret<int8?>(unsafe(myargv[i_0 + 1])))
        c2da_std_fprintf(unsafe(reinterpret<uint64>(unsafe(reinterpret<_IO_FILE?>(c2da_std_stderr())))), unsafe(addr<int8 const?>(c2da_str_201[0])), [C2daVaArg(tag = 3, i64 = 0, f64 = 0.0lf, raw = unsafe(reinterpret<uint64>(extra_defaults.filename)))])
    } else {
        extra_defaults.filename = unsafe(reinterpret<int8?>(unsafe(reinterpret<int8?>(M_StringJoin(unsafe(reinterpret<int8 const?>(configdir)), [C2daVaArg(tag = 3, i64 = 0, f64 = 0.0lf, raw = unsafe(reinterpret<uint64>(default_extra_config))), C2daVaArg(tag = 3, i64 = 0, f64 = 0.0lf, raw = unsafe(reinterpret<uint64>(null)))])))))
    }
    LoadDefaultCollection(unsafe(addr<default_collection_t?>(doom_defaults)))
    LoadDefaultCollection(unsafe(addr<default_collection_t?>(extra_defaults)))
    return
}
[sideeffects]
def private GetDefaultForName(var name_0 : int8?) : default_t? {
    var result_0 : default_t? = unsafe(reinterpret<default_t?>(unsafe(reinterpret<default_t?>(SearchCollection(unsafe(addr<default_collection_t?>(doom_defaults)), name_0)))))
    if (result_0 == null) {
        result_0 = unsafe(reinterpret<default_t?>(unsafe(reinterpret<default_t?>(SearchCollection(unsafe(addr<default_collection_t?>(extra_defaults)), name_0)))))
    }
    if (result_0 == null) {
        I_Error(unsafe(addr<int8?>(c2da_str_202[0])), [C2daVaArg(tag = 3, i64 = 0, f64 = 0.0lf, raw = unsafe(reinterpret<uint64>(name_0)))])
    }
    return unsafe(reinterpret<default_t?>(result_0))
}
[export, sideeffects]
def M_BindVariable(var name_1 : int8?; var location : uint8?) {
    var variable : default_t? = unsafe(reinterpret<default_t?>(unsafe(reinterpret<default_t?>(GetDefaultForName(name_1)))))
    variable.location = location
    variable.bound = 1u
    return
}
[export, sideeffects]
def M_SetVariable(var name_2 : int8?; var value_0 : int8?) : uint {
    var variable_0 : default_t? = unsafe(reinterpret<default_t?>(unsafe(reinterpret<default_t?>(GetDefaultForName(name_2)))))
    if (variable_0 == null || variable_0.bound == 0) {
        return 0u
    }
    SetVariable(variable_0, value_0)
    return 1u
}
[export, sideeffects]
def M_GetIntVariable(var name_3 : int8?) : int {
    var variable_1 : default_t? = unsafe(reinterpret<default_t?>(unsafe(reinterpret<default_t?>(GetDefaultForName(name_3)))))
    if (variable_1 == null || variable_1.bound == 0 || uint(variable_1.type_0) != 0u && uint(variable_1.type_0) != 1u) {
        return 0
    }
    return *unsafe(reinterpret<int?>(variable_1.location))
}
[export, sideeffects]
def M_GetStrVariable(var name_4 : int8?) : int8 const? {
    var variable_2 : default_t? = unsafe(reinterpret<default_t?>(unsafe(reinterpret<default_t?>(GetDefaultForName(name_4)))))
    if (variable_2 == null || variable_2.bound == 0 || uint(variable_2.type_0) != 2u) {
        return unsafe(reinterpret<int8 const?>(null))
    }
    return unsafe(reinterpret<int8 const?>(*unsafe(reinterpret<int8 const??>(variable_2.location))))
}
[export, sideeffects]
def M_GetFloatVariable(var name_5 : int8?) : float {
    var variable_3 : default_t? = unsafe(reinterpret<default_t?>(unsafe(reinterpret<default_t?>(GetDefaultForName(name_5)))))
    if (variable_3 == null || variable_3.bound == 0 || uint(variable_3.type_0) != 3u) {
        return 0.0
    }
    return *unsafe(reinterpret<float?>(variable_3.location))
}
[sideeffects]
def private GetDefaultConfigDir() : int8? {
    var result_1 : int8? = unsafe(reinterpret<int8?>(unsafe(reinterpret<int8?>(c2da_rt_malloc(2ul)))))
    unsafe(result_1[0]) = int8(46)
    unsafe(result_1[1]) = int8(0)
    return unsafe(reinterpret<int8?>(result_1))
}
[export, sideeffects]
def M_SetConfigDir(var dir : int8?) {
    if (dir != null) {
        configdir = unsafe(reinterpret<int8?>(dir))
    } else {
        configdir = unsafe(reinterpret<int8?>(unsafe(reinterpret<int8?>(GetDefaultConfigDir()))))
    }
    if (c2da_std_strcmp(unsafe(reinterpret<uint64>(configdir)), unsafe(reinterpret<uint64>(unsafe(addr(c2da_str_203[0]))))) != 0) {
        c2da_std_fprintf(unsafe(reinterpret<uint64>(unsafe(reinterpret<_IO_FILE?>(c2da_std_stderr())))), unsafe(addr<int8 const?>(c2da_str_204[0])), [C2daVaArg(tag = 3, i64 = 0, f64 = 0.0lf, raw = unsafe(reinterpret<uint64>(configdir)))])
    }
    M_MakeDirectory(configdir)
    return
}
[export, sideeffects]
def M_GetSaveGameDir(var iwadname : int8?) : int8? {
    var savegamedir : int8?
    if (c2da_std_strcmp(unsafe(reinterpret<uint64>(configdir)), unsafe(reinterpret<uint64>(unsafe(addr(c2da_str_203[0]))))) == 0) {
        savegamedir = unsafe(reinterpret<int8?>(unsafe(reinterpret<int8?>(c2da_std_strdup(unsafe(reinterpret<uint64>(unsafe(addr(c2da_str_203[0])))))))))
    } else {
        savegamedir = unsafe(reinterpret<int8?>(unsafe(reinterpret<int8?>(M_StringJoin(unsafe(reinterpret<int8 const?>(configdir)), [C2daVaArg(tag = 3, i64 = 0, f64 = 0.0lf, raw = unsafe(reinterpret<uint64>(unsafe(addr(c2da_str_205[0]))))), C2daVaArg(tag = 3, i64 = 0, f64 = 0.0lf, raw = unsafe(reinterpret<uint64>(unsafe(addr(c2da_str_206[0]))))), C2daVaArg(tag = 3, i64 = 0, f64 = 0.0lf, raw = unsafe(reinterpret<uint64>(null)))])))))
        M_MakeDirectory(savegamedir)
        c2da_std_fprintf(unsafe(reinterpret<uint64>(unsafe(reinterpret<_IO_FILE?>(c2da_std_stderr())))), unsafe(addr<int8 const?>(c2da_str_207[0])), [C2daVaArg(tag = 3, i64 = 0, f64 = 0.0lf, raw = unsafe(reinterpret<uint64>(savegamedir)))])
    }
    return unsafe(reinterpret<int8?>(savegamedir))
}
[sideeffects]
def private c2da_layout_proofs() {
    static_assert(typeinfo sizeof(type<_IO_FILE>) == 216, "C layout of _IO_FILE: sizeof")
    static_assert(typeinfo alignof(type<_IO_FILE>) == 8, "C layout of _IO_FILE: alignof")
    static_assert(typeinfo offsetof<_flags>(type<_IO_FILE>) == 0, "C layout of _IO_FILE: offsetof _flags")
    static_assert(typeinfo offsetof<_IO_read_ptr>(type<_IO_FILE>) == 8, "C layout of _IO_FILE: offsetof _IO_read_ptr")
    static_assert(typeinfo offsetof<_IO_read_end>(type<_IO_FILE>) == 16, "C layout of _IO_FILE: offsetof _IO_read_end")
    static_assert(typeinfo offsetof<_IO_read_base>(type<_IO_FILE>) == 24, "C layout of _IO_FILE: offsetof _IO_read_base")
    static_assert(typeinfo offsetof<_IO_write_base>(type<_IO_FILE>) == 32, "C layout of _IO_FILE: offsetof _IO_write_base")
    static_assert(typeinfo offsetof<_IO_write_ptr>(type<_IO_FILE>) == 40, "C layout of _IO_FILE: offsetof _IO_write_ptr")
    static_assert(typeinfo offsetof<_IO_write_end>(type<_IO_FILE>) == 48, "C layout of _IO_FILE: offsetof _IO_write_end")
    static_assert(typeinfo offsetof<_IO_buf_base>(type<_IO_FILE>) == 56, "C layout of _IO_FILE: offsetof _IO_buf_base")
    static_assert(typeinfo offsetof<_IO_buf_end>(type<_IO_FILE>) == 64, "C layout of _IO_FILE: offsetof _IO_buf_end")
    static_assert(typeinfo offsetof<_IO_save_base>(type<_IO_FILE>) == 72, "C layout of _IO_FILE: offsetof _IO_save_base")
    static_assert(typeinfo offsetof<_IO_backup_base>(type<_IO_FILE>) == 80, "C layout of _IO_FILE: offsetof _IO_backup_base")
    static_assert(typeinfo offsetof<_IO_save_end>(type<_IO_FILE>) == 88, "C layout of _IO_FILE: offsetof _IO_save_end")
    static_assert(typeinfo offsetof<_markers>(type<_IO_FILE>) == 96, "C layout of _IO_FILE: offsetof _markers")
    static_assert(typeinfo offsetof<_chain>(type<_IO_FILE>) == 104, "C layout of _IO_FILE: offsetof _chain")
    static_assert(typeinfo offsetof<_fileno>(type<_IO_FILE>) == 112, "C layout of _IO_FILE: offsetof _fileno")
    static_assert(typeinfo offsetof<_flags2>(type<_IO_FILE>) == 116, "C layout of _IO_FILE: offsetof _flags2")
    static_assert(typeinfo offsetof<_old_offset>(type<_IO_FILE>) == 120, "C layout of _IO_FILE: offsetof _old_offset")
    static_assert(typeinfo offsetof<_cur_column>(type<_IO_FILE>) == 128, "C layout of _IO_FILE: offsetof _cur_column")
    static_assert(typeinfo offsetof<_vtable_offset>(type<_IO_FILE>) == 130, "C layout of _IO_FILE: offsetof _vtable_offset")
    static_assert(typeinfo offsetof<_shortbuf>(type<_IO_FILE>) == 131, "C layout of _IO_FILE: offsetof _shortbuf")
    static_assert(typeinfo offsetof<_lock>(type<_IO_FILE>) == 136, "C layout of _IO_FILE: offsetof _lock")
    static_assert(typeinfo offsetof<_offset>(type<_IO_FILE>) == 144, "C layout of _IO_FILE: offsetof _offset")
    static_assert(typeinfo offsetof<_codecvt>(type<_IO_FILE>) == 152, "C layout of _IO_FILE: offsetof _codecvt")
    static_assert(typeinfo offsetof<_wide_data>(type<_IO_FILE>) == 160, "C layout of _IO_FILE: offsetof _wide_data")
    static_assert(typeinfo offsetof<_freeres_list>(type<_IO_FILE>) == 168, "C layout of _IO_FILE: offsetof _freeres_list")
    static_assert(typeinfo offsetof<_freeres_buf>(type<_IO_FILE>) == 176, "C layout of _IO_FILE: offsetof _freeres_buf")
    static_assert(typeinfo offsetof<c2da___pad5>(type<_IO_FILE>) == 184, "C layout of _IO_FILE: offsetof c2da___pad5")
    static_assert(typeinfo offsetof<_mode>(type<_IO_FILE>) == 192, "C layout of _IO_FILE: offsetof _mode")
    static_assert(typeinfo offsetof<_unused2>(type<_IO_FILE>) == 196, "C layout of _IO_FILE: offsetof _unused2")
    static_assert(typeinfo sizeof(type<FILE_0>) == 216, "C layout of FILE_0: sizeof")
    static_assert(typeinfo alignof(type<FILE_0>) == 8, "C layout of FILE_0: alignof")
    static_assert(typeinfo offsetof<_flags>(type<FILE_0>) == 0, "C layout of FILE_0: offsetof _flags")
    static_assert(typeinfo offsetof<_IO_read_ptr>(type<FILE_0>) == 8, "C layout of FILE_0: offsetof _IO_read_ptr")
    static_assert(typeinfo offsetof<_IO_read_end>(type<FILE_0>) == 16, "C layout of FILE_0: offsetof _IO_read_end")
    static_assert(typeinfo offsetof<_IO_read_base>(type<FILE_0>) == 24, "C layout of FILE_0: offsetof _IO_read_base")
    static_assert(typeinfo offsetof<_IO_write_base>(type<FILE_0>) == 32, "C layout of FILE_0: offsetof _IO_write_base")
    static_assert(typeinfo offsetof<_IO_write_ptr>(type<FILE_0>) == 40, "C layout of FILE_0: offsetof _IO_write_ptr")
    static_assert(typeinfo offsetof<_IO_write_end>(type<FILE_0>) == 48, "C layout of FILE_0: offsetof _IO_write_end")
    static_assert(typeinfo offsetof<_IO_buf_base>(type<FILE_0>) == 56, "C layout of FILE_0: offsetof _IO_buf_base")
    static_assert(typeinfo offsetof<_IO_buf_end>(type<FILE_0>) == 64, "C layout of FILE_0: offsetof _IO_buf_end")
    static_assert(typeinfo offsetof<_IO_save_base>(type<FILE_0>) == 72, "C layout of FILE_0: offsetof _IO_save_base")
    static_assert(typeinfo offsetof<_IO_backup_base>(type<FILE_0>) == 80, "C layout of FILE_0: offsetof _IO_backup_base")
    static_assert(typeinfo offsetof<_IO_save_end>(type<FILE_0>) == 88, "C layout of FILE_0: offsetof _IO_save_end")
    static_assert(typeinfo offsetof<_markers>(type<FILE_0>) == 96, "C layout of FILE_0: offsetof _markers")
    static_assert(typeinfo offsetof<_chain>(type<FILE_0>) == 104, "C layout of FILE_0: offsetof _chain")
    static_assert(typeinfo offsetof<_fileno>(type<FILE_0>) == 112, "C layout of FILE_0: offsetof _fileno")
    static_assert(typeinfo offsetof<_flags2>(type<FILE_0>) == 116, "C layout of FILE_0: offsetof _flags2")
    static_assert(typeinfo offsetof<_old_offset>(type<FILE_0>) == 120, "C layout of FILE_0: offsetof _old_offset")
    static_assert(typeinfo offsetof<_cur_column>(type<FILE_0>) == 128, "C layout of FILE_0: offsetof _cur_column")
    static_assert(typeinfo offsetof<_vtable_offset>(type<FILE_0>) == 130, "C layout of FILE_0: offsetof _vtable_offset")
    static_assert(typeinfo offsetof<_shortbuf>(type<FILE_0>) == 131, "C layout of FILE_0: offsetof _shortbuf")
    static_assert(typeinfo offsetof<_lock>(type<FILE_0>) == 136, "C layout of FILE_0: offsetof _lock")
    static_assert(typeinfo offsetof<_offset>(type<FILE_0>) == 144, "C layout of FILE_0: offsetof _offset")
    static_assert(typeinfo offsetof<_codecvt>(type<FILE_0>) == 152, "C layout of FILE_0: offsetof _codecvt")
    static_assert(typeinfo offsetof<_wide_data>(type<FILE_0>) == 160, "C layout of FILE_0: offsetof _wide_data")
    static_assert(typeinfo offsetof<_freeres_list>(type<FILE_0>) == 168, "C layout of FILE_0: offsetof _freeres_list")
    static_assert(typeinfo offsetof<_freeres_buf>(type<FILE_0>) == 176, "C layout of FILE_0: offsetof _freeres_buf")
    static_assert(typeinfo offsetof<c2da___pad5>(type<FILE_0>) == 184, "C layout of FILE_0: offsetof c2da___pad5")
    static_assert(typeinfo offsetof<_mode>(type<FILE_0>) == 192, "C layout of FILE_0: offsetof _mode")
    static_assert(typeinfo offsetof<_unused2>(type<FILE_0>) == 196, "C layout of FILE_0: offsetof _unused2")
    static_assert(typeinfo sizeof(type<default_t>) == 32, "C layout of default_t: sizeof")
    static_assert(typeinfo alignof(type<default_t>) == 8, "C layout of default_t: alignof")
    static_assert(typeinfo offsetof<name>(type<default_t>) == 0, "C layout of default_t: offsetof name")
    static_assert(typeinfo offsetof<location>(type<default_t>) == 8, "C layout of default_t: offsetof location")
    static_assert(typeinfo offsetof<type_0>(type<default_t>) == 16, "C layout of default_t: offsetof type_0")
    static_assert(typeinfo offsetof<untranslated>(type<default_t>) == 20, "C layout of default_t: offsetof untranslated")
    static_assert(typeinfo offsetof<original_translated>(type<default_t>) == 24, "C layout of default_t: offsetof original_translated")
    static_assert(typeinfo offsetof<bound>(type<default_t>) == 28, "C layout of default_t: offsetof bound")
    static_assert(typeinfo sizeof(type<default_collection_t>) == 24, "C layout of default_collection_t: sizeof")
    static_assert(typeinfo alignof(type<default_collection_t>) == 8, "C layout of default_collection_t: alignof")
    static_assert(typeinfo offsetof<defaults>(type<default_collection_t>) == 0, "C layout of default_collection_t: offsetof defaults")
    static_assert(typeinfo offsetof<numdefaults>(type<default_collection_t>) == 8, "C layout of default_collection_t: offsetof numdefaults")
    static_assert(typeinfo offsetof<filename>(type<default_collection_t>) == 16, "C layout of default_collection_t: offsetof filename")
}
