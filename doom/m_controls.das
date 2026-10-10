options gen2
options solid_context = true
options stack = 4194304
module m_controls public

require c2da_runtime
require i_system_cluster
require m_config
var private c2da_str_0 : array<int8> = [int8(107), int8(101), int8(121), int8(95), int8(114), int8(105), int8(103), int8(104), int8(116), int8(0)]

var private c2da_str_1 : array<int8> = [int8(107), int8(101), int8(121), int8(95), int8(108), int8(101), int8(102), int8(116), int8(0)]

var private c2da_str_2 : array<int8> = [int8(107), int8(101), int8(121), int8(95), int8(117), int8(112), int8(0)]

var private c2da_str_3 : array<int8> = [int8(107), int8(101), int8(121), int8(95), int8(100), int8(111), int8(119), int8(110), int8(0)]

var private c2da_str_4 : array<int8> = [int8(107), int8(101), int8(121), int8(95), int8(115), int8(116), int8(114), int8(97), int8(102), int8(101), int8(108), int8(101), int8(102), int8(116), int8(0)]

var private c2da_str_5 : array<int8> = [int8(107), int8(101), int8(121), int8(95), int8(115), int8(116), int8(114), int8(97), int8(102), int8(101), int8(114), int8(105), int8(103), int8(104), int8(116), int8(0)]

var private c2da_str_6 : array<int8> = [int8(107), int8(101), int8(121), int8(95), int8(102), int8(105), int8(114), int8(101), int8(0)]

var private c2da_str_7 : array<int8> = [int8(107), int8(101), int8(121), int8(95), int8(117), int8(115), int8(101), int8(0)]

var private c2da_str_8 : array<int8> = [int8(107), int8(101), int8(121), int8(95), int8(115), int8(116), int8(114), int8(97), int8(102), int8(101), int8(0)]

var private c2da_str_9 : array<int8> = [int8(107), int8(101), int8(121), int8(95), int8(115), int8(112), int8(101), int8(101), int8(100), int8(0)]

var private c2da_str_10 : array<int8> = [int8(109), int8(111), int8(117), int8(115), int8(101), int8(98), int8(95), int8(102), int8(105), int8(114), int8(101), int8(0)]

var private c2da_str_11 : array<int8> = [int8(109), int8(111), int8(117), int8(115), int8(101), int8(98), int8(95), int8(115), int8(116), int8(114), int8(97), int8(102), int8(101), int8(0)]

var private c2da_str_12 : array<int8> = [int8(109), int8(111), int8(117), int8(115), int8(101), int8(98), int8(95), int8(102), int8(111), int8(114), int8(119), int8(97), int8(114), int8(100), int8(0)]

var private c2da_str_13 : array<int8> = [int8(106), int8(111), int8(121), int8(98), int8(95), int8(102), int8(105), int8(114), int8(101), int8(0)]

var private c2da_str_14 : array<int8> = [int8(106), int8(111), int8(121), int8(98), int8(95), int8(115), int8(116), int8(114), int8(97), int8(102), int8(101), int8(0)]

var private c2da_str_15 : array<int8> = [int8(106), int8(111), int8(121), int8(98), int8(95), int8(117), int8(115), int8(101), int8(0)]

var private c2da_str_16 : array<int8> = [int8(106), int8(111), int8(121), int8(98), int8(95), int8(115), int8(112), int8(101), int8(101), int8(100), int8(0)]

var private c2da_str_17 : array<int8> = [int8(106), int8(111), int8(121), int8(98), int8(95), int8(109), int8(101), int8(110), int8(117), int8(95), int8(97), int8(99), int8(116), int8(105), int8(118), int8(97), int8(116), int8(101), int8(0)]

var private c2da_str_18 : array<int8> = [int8(106), int8(111), int8(121), int8(98), int8(95), int8(115), int8(116), int8(114), int8(97), int8(102), int8(101), int8(108), int8(101), int8(102), int8(116), int8(0)]

var private c2da_str_19 : array<int8> = [int8(106), int8(111), int8(121), int8(98), int8(95), int8(115), int8(116), int8(114), int8(97), int8(102), int8(101), int8(114), int8(105), int8(103), int8(104), int8(116), int8(0)]

var private c2da_str_20 : array<int8> = [int8(109), int8(111), int8(117), int8(115), int8(101), int8(98), int8(95), int8(115), int8(116), int8(114), int8(97), int8(102), int8(101), int8(108), int8(101), int8(102), int8(116), int8(0)]

var private c2da_str_21 : array<int8> = [int8(109), int8(111), int8(117), int8(115), int8(101), int8(98), int8(95), int8(115), int8(116), int8(114), int8(97), int8(102), int8(101), int8(114), int8(105), int8(103), int8(104), int8(116), int8(0)]

var private c2da_str_22 : array<int8> = [int8(109), int8(111), int8(117), int8(115), int8(101), int8(98), int8(95), int8(117), int8(115), int8(101), int8(0)]

var private c2da_str_23 : array<int8> = [int8(109), int8(111), int8(117), int8(115), int8(101), int8(98), int8(95), int8(98), int8(97), int8(99), int8(107), int8(119), int8(97), int8(114), int8(100), int8(0)]

var private c2da_str_24 : array<int8> = [int8(100), int8(99), int8(108), int8(105), int8(99), int8(107), int8(95), int8(117), int8(115), int8(101), int8(0)]

var private c2da_str_25 : array<int8> = [int8(107), int8(101), int8(121), int8(95), int8(112), int8(97), int8(117), int8(115), int8(101), int8(0)]

var private c2da_str_26 : array<int8> = [int8(107), int8(101), int8(121), int8(95), int8(109), int8(101), int8(115), int8(115), int8(97), int8(103), int8(101), int8(95), int8(114), int8(101), int8(102), int8(114), int8(101), int8(115), int8(104), int8(0)]

var private c2da_str_27 : array<int8> = [int8(107), int8(101), int8(121), int8(95), int8(102), int8(108), int8(121), int8(117), int8(112), int8(0)]

var private c2da_str_28 : array<int8> = [int8(107), int8(101), int8(121), int8(95), int8(102), int8(108), int8(121), int8(100), int8(111), int8(119), int8(110), int8(0)]

var private c2da_str_29 : array<int8> = [int8(107), int8(101), int8(121), int8(95), int8(102), int8(108), int8(121), int8(99), int8(101), int8(110), int8(116), int8(101), int8(114), int8(0)]

var private c2da_str_30 : array<int8> = [int8(107), int8(101), int8(121), int8(95), int8(108), int8(111), int8(111), int8(107), int8(117), int8(112), int8(0)]

var private c2da_str_31 : array<int8> = [int8(107), int8(101), int8(121), int8(95), int8(108), int8(111), int8(111), int8(107), int8(100), int8(111), int8(119), int8(110), int8(0)]

var private c2da_str_32 : array<int8> = [int8(107), int8(101), int8(121), int8(95), int8(108), int8(111), int8(111), int8(107), int8(99), int8(101), int8(110), int8(116), int8(101), int8(114), int8(0)]

var private c2da_str_33 : array<int8> = [int8(107), int8(101), int8(121), int8(95), int8(105), int8(110), int8(118), int8(108), int8(101), int8(102), int8(116), int8(0)]

var private c2da_str_34 : array<int8> = [int8(107), int8(101), int8(121), int8(95), int8(105), int8(110), int8(118), int8(114), int8(105), int8(103), int8(104), int8(116), int8(0)]

var private c2da_str_35 : array<int8> = [int8(107), int8(101), int8(121), int8(95), int8(117), int8(115), int8(101), int8(97), int8(114), int8(116), int8(105), int8(102), int8(97), int8(99), int8(116), int8(0)]

var private c2da_str_36 : array<int8> = [int8(107), int8(101), int8(121), int8(95), int8(106), int8(117), int8(109), int8(112), int8(0)]

var private c2da_str_37 : array<int8> = [int8(109), int8(111), int8(117), int8(115), int8(101), int8(98), int8(95), int8(106), int8(117), int8(109), int8(112), int8(0)]

var private c2da_str_38 : array<int8> = [int8(106), int8(111), int8(121), int8(98), int8(95), int8(106), int8(117), int8(109), int8(112), int8(0)]

var private c2da_str_39 : array<int8> = [int8(107), int8(101), int8(121), int8(95), int8(97), int8(114), int8(116), int8(105), int8(95), int8(97), int8(108), int8(108), int8(0)]

var private c2da_str_40 : array<int8> = [int8(107), int8(101), int8(121), int8(95), int8(97), int8(114), int8(116), int8(105), int8(95), int8(104), int8(101), int8(97), int8(108), int8(116), int8(104), int8(0)]

var private c2da_str_41 : array<int8> = [int8(107), int8(101), int8(121), int8(95), int8(97), int8(114), int8(116), int8(105), int8(95), int8(112), int8(111), int8(105), int8(115), int8(111), int8(110), int8(98), int8(97), int8(103), int8(0)]

var private c2da_str_42 : array<int8> = [int8(107), int8(101), int8(121), int8(95), int8(97), int8(114), int8(116), int8(105), int8(95), int8(98), int8(108), int8(97), int8(115), int8(116), int8(114), int8(97), int8(100), int8(105), int8(117), int8(115), int8(0)]

var private c2da_str_43 : array<int8> = [int8(107), int8(101), int8(121), int8(95), int8(97), int8(114), int8(116), int8(105), int8(95), int8(116), int8(101), int8(108), int8(101), int8(112), int8(111), int8(114), int8(116), int8(0)]

var private c2da_str_44 : array<int8> = [int8(107), int8(101), int8(121), int8(95), int8(97), int8(114), int8(116), int8(105), int8(95), int8(116), int8(101), int8(108), int8(101), int8(112), int8(111), int8(114), int8(116), int8(111), int8(116), int8(104), int8(101), int8(114), int8(0)]

var private c2da_str_45 : array<int8> = [int8(107), int8(101), int8(121), int8(95), int8(97), int8(114), int8(116), int8(105), int8(95), int8(101), int8(103), int8(103), int8(0)]

var private c2da_str_46 : array<int8> = [int8(107), int8(101), int8(121), int8(95), int8(97), int8(114), int8(116), int8(105), int8(95), int8(105), int8(110), int8(118), int8(117), int8(108), int8(110), int8(101), int8(114), int8(97), int8(98), int8(105), int8(108), int8(105), int8(116), int8(121), int8(0)]

var private c2da_str_47 : array<int8> = [int8(107), int8(101), int8(121), int8(95), int8(108), int8(111), int8(111), int8(107), int8(85), int8(112), int8(0)]

var private c2da_str_48 : array<int8> = [int8(107), int8(101), int8(121), int8(95), int8(108), int8(111), int8(111), int8(107), int8(68), int8(111), int8(119), int8(110), int8(0)]

var private c2da_str_49 : array<int8> = [int8(107), int8(101), int8(121), int8(95), int8(105), int8(110), int8(118), int8(76), int8(101), int8(102), int8(116), int8(0)]

var private c2da_str_50 : array<int8> = [int8(107), int8(101), int8(121), int8(95), int8(105), int8(110), int8(118), int8(82), int8(105), int8(103), int8(104), int8(116), int8(0)]

var private c2da_str_51 : array<int8> = [int8(107), int8(101), int8(121), int8(95), int8(117), int8(115), int8(101), int8(72), int8(101), int8(97), int8(108), int8(116), int8(104), int8(0)]

var private c2da_str_52 : array<int8> = [int8(107), int8(101), int8(121), int8(95), int8(105), int8(110), int8(118), int8(113), int8(117), int8(101), int8(114), int8(121), int8(0)]

var private c2da_str_53 : array<int8> = [int8(107), int8(101), int8(121), int8(95), int8(109), int8(105), int8(115), int8(115), int8(105), int8(111), int8(110), int8(0)]

var private c2da_str_54 : array<int8> = [int8(107), int8(101), int8(121), int8(95), int8(105), int8(110), int8(118), int8(80), int8(111), int8(112), int8(0)]

var private c2da_str_55 : array<int8> = [int8(107), int8(101), int8(121), int8(95), int8(105), int8(110), int8(118), int8(75), int8(101), int8(121), int8(0)]

var private c2da_str_56 : array<int8> = [int8(107), int8(101), int8(121), int8(95), int8(105), int8(110), int8(118), int8(72), int8(111), int8(109), int8(101), int8(0)]

var private c2da_str_57 : array<int8> = [int8(107), int8(101), int8(121), int8(95), int8(105), int8(110), int8(118), int8(69), int8(110), int8(100), int8(0)]

var private c2da_str_58 : array<int8> = [int8(107), int8(101), int8(121), int8(95), int8(105), int8(110), int8(118), int8(85), int8(115), int8(101), int8(0)]

var private c2da_str_59 : array<int8> = [int8(107), int8(101), int8(121), int8(95), int8(105), int8(110), int8(118), int8(68), int8(114), int8(111), int8(112), int8(0)]

var private c2da_str_60 : array<int8> = [int8(107), int8(101), int8(121), int8(95), int8(119), int8(101), int8(97), int8(112), int8(111), int8(110), int8(49), int8(0)]

var private c2da_str_61 : array<int8> = [int8(107), int8(101), int8(121), int8(95), int8(119), int8(101), int8(97), int8(112), int8(111), int8(110), int8(50), int8(0)]

var private c2da_str_62 : array<int8> = [int8(107), int8(101), int8(121), int8(95), int8(119), int8(101), int8(97), int8(112), int8(111), int8(110), int8(51), int8(0)]

var private c2da_str_63 : array<int8> = [int8(107), int8(101), int8(121), int8(95), int8(119), int8(101), int8(97), int8(112), int8(111), int8(110), int8(52), int8(0)]

var private c2da_str_64 : array<int8> = [int8(107), int8(101), int8(121), int8(95), int8(119), int8(101), int8(97), int8(112), int8(111), int8(110), int8(53), int8(0)]

var private c2da_str_65 : array<int8> = [int8(107), int8(101), int8(121), int8(95), int8(119), int8(101), int8(97), int8(112), int8(111), int8(110), int8(54), int8(0)]

var private c2da_str_66 : array<int8> = [int8(107), int8(101), int8(121), int8(95), int8(119), int8(101), int8(97), int8(112), int8(111), int8(110), int8(55), int8(0)]

var private c2da_str_67 : array<int8> = [int8(107), int8(101), int8(121), int8(95), int8(119), int8(101), int8(97), int8(112), int8(111), int8(110), int8(56), int8(0)]

var private c2da_str_68 : array<int8> = [int8(107), int8(101), int8(121), int8(95), int8(112), int8(114), int8(101), int8(118), int8(119), int8(101), int8(97), int8(112), int8(111), int8(110), int8(0)]

var private c2da_str_69 : array<int8> = [int8(107), int8(101), int8(121), int8(95), int8(110), int8(101), int8(120), int8(116), int8(119), int8(101), int8(97), int8(112), int8(111), int8(110), int8(0)]

var private c2da_str_70 : array<int8> = [int8(106), int8(111), int8(121), int8(98), int8(95), int8(112), int8(114), int8(101), int8(118), int8(119), int8(101), int8(97), int8(112), int8(111), int8(110), int8(0)]

var private c2da_str_71 : array<int8> = [int8(106), int8(111), int8(121), int8(98), int8(95), int8(110), int8(101), int8(120), int8(116), int8(119), int8(101), int8(97), int8(112), int8(111), int8(110), int8(0)]

var private c2da_str_72 : array<int8> = [int8(109), int8(111), int8(117), int8(115), int8(101), int8(98), int8(95), int8(112), int8(114), int8(101), int8(118), int8(119), int8(101), int8(97), int8(112), int8(111), int8(110), int8(0)]

var private c2da_str_73 : array<int8> = [int8(109), int8(111), int8(117), int8(115), int8(101), int8(98), int8(95), int8(110), int8(101), int8(120), int8(116), int8(119), int8(101), int8(97), int8(112), int8(111), int8(110), int8(0)]

var private c2da_str_74 : array<int8> = [int8(107), int8(101), int8(121), int8(95), int8(109), int8(97), int8(112), int8(95), int8(110), int8(111), int8(114), int8(116), int8(104), int8(0)]

var private c2da_str_75 : array<int8> = [int8(107), int8(101), int8(121), int8(95), int8(109), int8(97), int8(112), int8(95), int8(115), int8(111), int8(117), int8(116), int8(104), int8(0)]

var private c2da_str_76 : array<int8> = [int8(107), int8(101), int8(121), int8(95), int8(109), int8(97), int8(112), int8(95), int8(101), int8(97), int8(115), int8(116), int8(0)]

var private c2da_str_77 : array<int8> = [int8(107), int8(101), int8(121), int8(95), int8(109), int8(97), int8(112), int8(95), int8(119), int8(101), int8(115), int8(116), int8(0)]

var private c2da_str_78 : array<int8> = [int8(107), int8(101), int8(121), int8(95), int8(109), int8(97), int8(112), int8(95), int8(122), int8(111), int8(111), int8(109), int8(105), int8(110), int8(0)]

var private c2da_str_79 : array<int8> = [int8(107), int8(101), int8(121), int8(95), int8(109), int8(97), int8(112), int8(95), int8(122), int8(111), int8(111), int8(109), int8(111), int8(117), int8(116), int8(0)]

var private c2da_str_80 : array<int8> = [int8(107), int8(101), int8(121), int8(95), int8(109), int8(97), int8(112), int8(95), int8(116), int8(111), int8(103), int8(103), int8(108), int8(101), int8(0)]

var private c2da_str_81 : array<int8> = [int8(107), int8(101), int8(121), int8(95), int8(109), int8(97), int8(112), int8(95), int8(109), int8(97), int8(120), int8(122), int8(111), int8(111), int8(109), int8(0)]

var private c2da_str_82 : array<int8> = [int8(107), int8(101), int8(121), int8(95), int8(109), int8(97), int8(112), int8(95), int8(102), int8(111), int8(108), int8(108), int8(111), int8(119), int8(0)]

var private c2da_str_83 : array<int8> = [int8(107), int8(101), int8(121), int8(95), int8(109), int8(97), int8(112), int8(95), int8(103), int8(114), int8(105), int8(100), int8(0)]

var private c2da_str_84 : array<int8> = [int8(107), int8(101), int8(121), int8(95), int8(109), int8(97), int8(112), int8(95), int8(109), int8(97), int8(114), int8(107), int8(0)]

var private c2da_str_85 : array<int8> = [int8(107), int8(101), int8(121), int8(95), int8(109), int8(97), int8(112), int8(95), int8(99), int8(108), int8(101), int8(97), int8(114), int8(109), int8(97), int8(114), int8(107), int8(0)]

var private c2da_str_86 : array<int8> = [int8(107), int8(101), int8(121), int8(95), int8(109), int8(101), int8(110), int8(117), int8(95), int8(97), int8(99), int8(116), int8(105), int8(118), int8(97), int8(116), int8(101), int8(0)]

var private c2da_str_87 : array<int8> = [int8(107), int8(101), int8(121), int8(95), int8(109), int8(101), int8(110), int8(117), int8(95), int8(117), int8(112), int8(0)]

var private c2da_str_88 : array<int8> = [int8(107), int8(101), int8(121), int8(95), int8(109), int8(101), int8(110), int8(117), int8(95), int8(100), int8(111), int8(119), int8(110), int8(0)]

var private c2da_str_89 : array<int8> = [int8(107), int8(101), int8(121), int8(95), int8(109), int8(101), int8(110), int8(117), int8(95), int8(108), int8(101), int8(102), int8(116), int8(0)]

var private c2da_str_90 : array<int8> = [int8(107), int8(101), int8(121), int8(95), int8(109), int8(101), int8(110), int8(117), int8(95), int8(114), int8(105), int8(103), int8(104), int8(116), int8(0)]

var private c2da_str_91 : array<int8> = [int8(107), int8(101), int8(121), int8(95), int8(109), int8(101), int8(110), int8(117), int8(95), int8(98), int8(97), int8(99), int8(107), int8(0)]

var private c2da_str_92 : array<int8> = [int8(107), int8(101), int8(121), int8(95), int8(109), int8(101), int8(110), int8(117), int8(95), int8(102), int8(111), int8(114), int8(119), int8(97), int8(114), int8(100), int8(0)]

var private c2da_str_93 : array<int8> = [int8(107), int8(101), int8(121), int8(95), int8(109), int8(101), int8(110), int8(117), int8(95), int8(99), int8(111), int8(110), int8(102), int8(105), int8(114), int8(109), int8(0)]

var private c2da_str_94 : array<int8> = [int8(107), int8(101), int8(121), int8(95), int8(109), int8(101), int8(110), int8(117), int8(95), int8(97), int8(98), int8(111), int8(114), int8(116), int8(0)]

var private c2da_str_95 : array<int8> = [int8(107), int8(101), int8(121), int8(95), int8(109), int8(101), int8(110), int8(117), int8(95), int8(104), int8(101), int8(108), int8(112), int8(0)]

var private c2da_str_96 : array<int8> = [int8(107), int8(101), int8(121), int8(95), int8(109), int8(101), int8(110), int8(117), int8(95), int8(115), int8(97), int8(118), int8(101), int8(0)]

var private c2da_str_97 : array<int8> = [int8(107), int8(101), int8(121), int8(95), int8(109), int8(101), int8(110), int8(117), int8(95), int8(108), int8(111), int8(97), int8(100), int8(0)]

var private c2da_str_98 : array<int8> = [int8(107), int8(101), int8(121), int8(95), int8(109), int8(101), int8(110), int8(117), int8(95), int8(118), int8(111), int8(108), int8(117), int8(109), int8(101), int8(0)]

var private c2da_str_99 : array<int8> = [int8(107), int8(101), int8(121), int8(95), int8(109), int8(101), int8(110), int8(117), int8(95), int8(100), int8(101), int8(116), int8(97), int8(105), int8(108), int8(0)]

var private c2da_str_100 : array<int8> = [int8(107), int8(101), int8(121), int8(95), int8(109), int8(101), int8(110), int8(117), int8(95), int8(113), int8(115), int8(97), int8(118), int8(101), int8(0)]

var private c2da_str_101 : array<int8> = [int8(107), int8(101), int8(121), int8(95), int8(109), int8(101), int8(110), int8(117), int8(95), int8(101), int8(110), int8(100), int8(103), int8(97), int8(109), int8(101), int8(0)]

var private c2da_str_102 : array<int8> = [int8(107), int8(101), int8(121), int8(95), int8(109), int8(101), int8(110), int8(117), int8(95), int8(109), int8(101), int8(115), int8(115), int8(97), int8(103), int8(101), int8(115), int8(0)]

var private c2da_str_103 : array<int8> = [int8(107), int8(101), int8(121), int8(95), int8(109), int8(101), int8(110), int8(117), int8(95), int8(113), int8(108), int8(111), int8(97), int8(100), int8(0)]

var private c2da_str_104 : array<int8> = [int8(107), int8(101), int8(121), int8(95), int8(109), int8(101), int8(110), int8(117), int8(95), int8(113), int8(117), int8(105), int8(116), int8(0)]

var private c2da_str_105 : array<int8> = [int8(107), int8(101), int8(121), int8(95), int8(109), int8(101), int8(110), int8(117), int8(95), int8(103), int8(97), int8(109), int8(109), int8(97), int8(0)]

var private c2da_str_106 : array<int8> = [int8(107), int8(101), int8(121), int8(95), int8(109), int8(101), int8(110), int8(117), int8(95), int8(105), int8(110), int8(99), int8(115), int8(99), int8(114), int8(101), int8(101), int8(110), int8(0)]

var private c2da_str_107 : array<int8> = [int8(107), int8(101), int8(121), int8(95), int8(109), int8(101), int8(110), int8(117), int8(95), int8(100), int8(101), int8(99), int8(115), int8(99), int8(114), int8(101), int8(101), int8(110), int8(0)]

var private c2da_str_108 : array<int8> = [int8(107), int8(101), int8(121), int8(95), int8(109), int8(101), int8(110), int8(117), int8(95), int8(115), int8(99), int8(114), int8(101), int8(101), int8(110), int8(115), int8(104), int8(111), int8(116), int8(0)]

var private c2da_str_109 : array<int8> = [int8(107), int8(101), int8(121), int8(95), int8(100), int8(101), int8(109), int8(111), int8(95), int8(113), int8(117), int8(105), int8(116), int8(0)]

var private c2da_str_110 : array<int8> = [int8(107), int8(101), int8(121), int8(95), int8(115), int8(112), int8(121), int8(0)]

var private c2da_str_111 : array<int8> = [int8(107), int8(101), int8(121), int8(95), int8(109), int8(117), int8(108), int8(116), int8(105), int8(95), int8(109), int8(115), int8(103), int8(0)]

var private c2da_str_112 : array<int8> = [int8(107), int8(101), int8(121), int8(95), int8(109), int8(117), int8(108), int8(116), int8(105), int8(95), int8(109), int8(115), int8(103), int8(112), int8(108), int8(97), int8(121), int8(101), int8(114), int8(37), int8(105), int8(0)]

var key_right : int = 174

var key_left : int = 172

var key_up : int = 173

var key_down : int = 175

var key_strafeleft : int = 160

var key_straferight : int = 161

var key_fire : int = 163

var key_use : int = 162

var key_strafe : int = 128 + 56

var key_speed : int = 128 + 54

var key_flyup : int = 128 + 73

var key_flydown : int = 128 + 82

var key_flycenter : int = 128 + 71

var key_lookup : int = 128 + 81

var key_lookdown : int = 128 + 83

var key_lookcenter : int = 128 + 79

var key_invleft : int = 91

var key_invright : int = 93

var key_useartifact : int = 13

var key_jump : int = 47

var key_arti_all : int = 127

var key_arti_health : int = 92

var key_arti_poisonbag : int = 48

var key_arti_blastradius : int = 57

var key_arti_teleport : int = 56

var key_arti_teleportother : int = 55

var key_arti_egg : int = 54

var key_arti_invulnerability : int = 53

var key_usehealth : int = 104

var key_invquery : int = 113

var key_mission : int = 119

var key_invpop : int = 122

var key_invkey : int = 107

var key_invhome : int = 128 + 71

var key_invend : int = 128 + 79

var key_invuse : int = 13

var key_invdrop : int = 127

var mousebfire : int = 0

var mousebstrafe : int = 1

var mousebforward : int = 2

var mousebjump : int = -1

var mousebstrafeleft : int = -1

var mousebstraferight : int = -1

var mousebbackward : int = -1

var mousebuse : int = -1

var mousebprevweapon : int = -1

var mousebnextweapon : int = -1

var key_message_refresh : int = 13

var key_pause : int = 255

var key_demo_quit : int = 113

var key_spy : int = 128 + 88

var key_multi_msg : int = 116

var key_multi_msgplayer : int[8]

var key_weapon1 : int = 49

var key_weapon2 : int = 50

var key_weapon3 : int = 51

var key_weapon4 : int = 52

var key_weapon5 : int = 53

var key_weapon6 : int = 54

var key_weapon7 : int = 55

var key_weapon8 : int = 56

var key_prevweapon : int = 0

var key_nextweapon : int = 0

var key_map_north : int = 173

var key_map_south : int = 175

var key_map_east : int = 174

var key_map_west : int = 172

var key_map_zoomin : int = 61

var key_map_zoomout : int = 45

var key_map_toggle : int = 9

var key_map_maxzoom : int = 48

var key_map_follow : int = 102

var key_map_grid : int = 103

var key_map_mark : int = 109

var key_map_clearmark : int = 99

var key_menu_activate : int = 27

var key_menu_up : int = 173

var key_menu_down : int = 175

var key_menu_left : int = 172

var key_menu_right : int = 174

var key_menu_back : int = 127

var key_menu_forward : int = 13

var key_menu_confirm : int = 121

var key_menu_abort : int = 110

var key_menu_help : int = 128 + 59

var key_menu_save : int = 128 + 60

var key_menu_load : int = 128 + 61

var key_menu_volume : int = 128 + 62

var key_menu_detail : int = 128 + 63

var key_menu_qsave : int = 128 + 64

var key_menu_endgame : int = 128 + 65

var key_menu_messages : int = 128 + 66

var key_menu_qload : int = 128 + 67

var key_menu_quit : int = 128 + 68

var key_menu_gamma : int = 128 + 87

var key_menu_incscreen : int = 61

var key_menu_decscreen : int = 45

var key_menu_screenshot : int = 0

var joybfire : int = 0

var joybstrafe : int = 1

var joybuse : int = 3

var joybspeed : int = 2

var joybstrafeleft : int = -1

var joybstraferight : int = -1

var joybjump : int = -1

var joybprevweapon : int = -1

var joybnextweapon : int = -1

var joybmenu : int = -1

var dclick_use : int = 1

[export, sideeffects]
def M_BindBaseControls() {
    M_BindVariable(unsafe(addr<int8?>(c2da_str_0[0])), unsafe(addr<uint8?>(key_right)))
    M_BindVariable(unsafe(addr<int8?>(c2da_str_1[0])), unsafe(addr<uint8?>(key_left)))
    M_BindVariable(unsafe(addr<int8?>(c2da_str_2[0])), unsafe(addr<uint8?>(key_up)))
    M_BindVariable(unsafe(addr<int8?>(c2da_str_3[0])), unsafe(addr<uint8?>(key_down)))
    M_BindVariable(unsafe(addr<int8?>(c2da_str_4[0])), unsafe(addr<uint8?>(key_strafeleft)))
    M_BindVariable(unsafe(addr<int8?>(c2da_str_5[0])), unsafe(addr<uint8?>(key_straferight)))
    M_BindVariable(unsafe(addr<int8?>(c2da_str_6[0])), unsafe(addr<uint8?>(key_fire)))
    M_BindVariable(unsafe(addr<int8?>(c2da_str_7[0])), unsafe(addr<uint8?>(key_use)))
    M_BindVariable(unsafe(addr<int8?>(c2da_str_8[0])), unsafe(addr<uint8?>(key_strafe)))
    M_BindVariable(unsafe(addr<int8?>(c2da_str_9[0])), unsafe(addr<uint8?>(key_speed)))
    M_BindVariable(unsafe(addr<int8?>(c2da_str_10[0])), unsafe(addr<uint8?>(mousebfire)))
    M_BindVariable(unsafe(addr<int8?>(c2da_str_11[0])), unsafe(addr<uint8?>(mousebstrafe)))
    M_BindVariable(unsafe(addr<int8?>(c2da_str_12[0])), unsafe(addr<uint8?>(mousebforward)))
    M_BindVariable(unsafe(addr<int8?>(c2da_str_13[0])), unsafe(addr<uint8?>(joybfire)))
    M_BindVariable(unsafe(addr<int8?>(c2da_str_14[0])), unsafe(addr<uint8?>(joybstrafe)))
    M_BindVariable(unsafe(addr<int8?>(c2da_str_15[0])), unsafe(addr<uint8?>(joybuse)))
    M_BindVariable(unsafe(addr<int8?>(c2da_str_16[0])), unsafe(addr<uint8?>(joybspeed)))
    M_BindVariable(unsafe(addr<int8?>(c2da_str_17[0])), unsafe(addr<uint8?>(joybmenu)))
    M_BindVariable(unsafe(addr<int8?>(c2da_str_18[0])), unsafe(addr<uint8?>(joybstrafeleft)))
    M_BindVariable(unsafe(addr<int8?>(c2da_str_19[0])), unsafe(addr<uint8?>(joybstraferight)))
    M_BindVariable(unsafe(addr<int8?>(c2da_str_20[0])), unsafe(addr<uint8?>(mousebstrafeleft)))
    M_BindVariable(unsafe(addr<int8?>(c2da_str_21[0])), unsafe(addr<uint8?>(mousebstraferight)))
    M_BindVariable(unsafe(addr<int8?>(c2da_str_22[0])), unsafe(addr<uint8?>(mousebuse)))
    M_BindVariable(unsafe(addr<int8?>(c2da_str_23[0])), unsafe(addr<uint8?>(mousebbackward)))
    M_BindVariable(unsafe(addr<int8?>(c2da_str_24[0])), unsafe(addr<uint8?>(dclick_use)))
    M_BindVariable(unsafe(addr<int8?>(c2da_str_25[0])), unsafe(addr<uint8?>(key_pause)))
    M_BindVariable(unsafe(addr<int8?>(c2da_str_26[0])), unsafe(addr<uint8?>(key_message_refresh)))
    return
}
[export, sideeffects]
def M_BindHereticControls() {
    M_BindVariable(unsafe(addr<int8?>(c2da_str_27[0])), unsafe(addr<uint8?>(key_flyup)))
    M_BindVariable(unsafe(addr<int8?>(c2da_str_28[0])), unsafe(addr<uint8?>(key_flydown)))
    M_BindVariable(unsafe(addr<int8?>(c2da_str_29[0])), unsafe(addr<uint8?>(key_flycenter)))
    M_BindVariable(unsafe(addr<int8?>(c2da_str_30[0])), unsafe(addr<uint8?>(key_lookup)))
    M_BindVariable(unsafe(addr<int8?>(c2da_str_31[0])), unsafe(addr<uint8?>(key_lookdown)))
    M_BindVariable(unsafe(addr<int8?>(c2da_str_32[0])), unsafe(addr<uint8?>(key_lookcenter)))
    M_BindVariable(unsafe(addr<int8?>(c2da_str_33[0])), unsafe(addr<uint8?>(key_invleft)))
    M_BindVariable(unsafe(addr<int8?>(c2da_str_34[0])), unsafe(addr<uint8?>(key_invright)))
    M_BindVariable(unsafe(addr<int8?>(c2da_str_35[0])), unsafe(addr<uint8?>(key_useartifact)))
    return
}
[export, sideeffects]
def M_BindHexenControls() {
    M_BindVariable(unsafe(addr<int8?>(c2da_str_36[0])), unsafe(addr<uint8?>(key_jump)))
    M_BindVariable(unsafe(addr<int8?>(c2da_str_37[0])), unsafe(addr<uint8?>(mousebjump)))
    M_BindVariable(unsafe(addr<int8?>(c2da_str_38[0])), unsafe(addr<uint8?>(joybjump)))
    M_BindVariable(unsafe(addr<int8?>(c2da_str_39[0])), unsafe(addr<uint8?>(key_arti_all)))
    M_BindVariable(unsafe(addr<int8?>(c2da_str_40[0])), unsafe(addr<uint8?>(key_arti_health)))
    M_BindVariable(unsafe(addr<int8?>(c2da_str_41[0])), unsafe(addr<uint8?>(key_arti_poisonbag)))
    M_BindVariable(unsafe(addr<int8?>(c2da_str_42[0])), unsafe(addr<uint8?>(key_arti_blastradius)))
    M_BindVariable(unsafe(addr<int8?>(c2da_str_43[0])), unsafe(addr<uint8?>(key_arti_teleport)))
    M_BindVariable(unsafe(addr<int8?>(c2da_str_44[0])), unsafe(addr<uint8?>(key_arti_teleportother)))
    M_BindVariable(unsafe(addr<int8?>(c2da_str_45[0])), unsafe(addr<uint8?>(key_arti_egg)))
    M_BindVariable(unsafe(addr<int8?>(c2da_str_46[0])), unsafe(addr<uint8?>(key_arti_invulnerability)))
    return
}
[export, sideeffects]
def M_BindStrifeControls() {
    key_message_refresh = 47
    key_jump = 97
    key_lookup = 128 + 73
    key_lookdown = 128 + 81
    key_invleft = 128 + 82
    key_invright = 128 + 83
    M_BindVariable(unsafe(addr<int8?>(c2da_str_36[0])), unsafe(addr<uint8?>(key_jump)))
    M_BindVariable(unsafe(addr<int8?>(c2da_str_47[0])), unsafe(addr<uint8?>(key_lookup)))
    M_BindVariable(unsafe(addr<int8?>(c2da_str_48[0])), unsafe(addr<uint8?>(key_lookdown)))
    M_BindVariable(unsafe(addr<int8?>(c2da_str_49[0])), unsafe(addr<uint8?>(key_invleft)))
    M_BindVariable(unsafe(addr<int8?>(c2da_str_50[0])), unsafe(addr<uint8?>(key_invright)))
    M_BindVariable(unsafe(addr<int8?>(c2da_str_51[0])), unsafe(addr<uint8?>(key_usehealth)))
    M_BindVariable(unsafe(addr<int8?>(c2da_str_52[0])), unsafe(addr<uint8?>(key_invquery)))
    M_BindVariable(unsafe(addr<int8?>(c2da_str_53[0])), unsafe(addr<uint8?>(key_mission)))
    M_BindVariable(unsafe(addr<int8?>(c2da_str_54[0])), unsafe(addr<uint8?>(key_invpop)))
    M_BindVariable(unsafe(addr<int8?>(c2da_str_55[0])), unsafe(addr<uint8?>(key_invkey)))
    M_BindVariable(unsafe(addr<int8?>(c2da_str_56[0])), unsafe(addr<uint8?>(key_invhome)))
    M_BindVariable(unsafe(addr<int8?>(c2da_str_57[0])), unsafe(addr<uint8?>(key_invend)))
    M_BindVariable(unsafe(addr<int8?>(c2da_str_58[0])), unsafe(addr<uint8?>(key_invuse)))
    M_BindVariable(unsafe(addr<int8?>(c2da_str_59[0])), unsafe(addr<uint8?>(key_invdrop)))
    M_BindVariable(unsafe(addr<int8?>(c2da_str_37[0])), unsafe(addr<uint8?>(mousebjump)))
    M_BindVariable(unsafe(addr<int8?>(c2da_str_38[0])), unsafe(addr<uint8?>(joybjump)))
    return
}
[export, sideeffects]
def M_BindWeaponControls() {
    M_BindVariable(unsafe(addr<int8?>(c2da_str_60[0])), unsafe(addr<uint8?>(key_weapon1)))
    M_BindVariable(unsafe(addr<int8?>(c2da_str_61[0])), unsafe(addr<uint8?>(key_weapon2)))
    M_BindVariable(unsafe(addr<int8?>(c2da_str_62[0])), unsafe(addr<uint8?>(key_weapon3)))
    M_BindVariable(unsafe(addr<int8?>(c2da_str_63[0])), unsafe(addr<uint8?>(key_weapon4)))
    M_BindVariable(unsafe(addr<int8?>(c2da_str_64[0])), unsafe(addr<uint8?>(key_weapon5)))
    M_BindVariable(unsafe(addr<int8?>(c2da_str_65[0])), unsafe(addr<uint8?>(key_weapon6)))
    M_BindVariable(unsafe(addr<int8?>(c2da_str_66[0])), unsafe(addr<uint8?>(key_weapon7)))
    M_BindVariable(unsafe(addr<int8?>(c2da_str_67[0])), unsafe(addr<uint8?>(key_weapon8)))
    M_BindVariable(unsafe(addr<int8?>(c2da_str_68[0])), unsafe(addr<uint8?>(key_prevweapon)))
    M_BindVariable(unsafe(addr<int8?>(c2da_str_69[0])), unsafe(addr<uint8?>(key_nextweapon)))
    M_BindVariable(unsafe(addr<int8?>(c2da_str_70[0])), unsafe(addr<uint8?>(joybprevweapon)))
    M_BindVariable(unsafe(addr<int8?>(c2da_str_71[0])), unsafe(addr<uint8?>(joybnextweapon)))
    M_BindVariable(unsafe(addr<int8?>(c2da_str_72[0])), unsafe(addr<uint8?>(mousebprevweapon)))
    M_BindVariable(unsafe(addr<int8?>(c2da_str_73[0])), unsafe(addr<uint8?>(mousebnextweapon)))
    return
}
[export, sideeffects]
def M_BindMapControls() {
    M_BindVariable(unsafe(addr<int8?>(c2da_str_74[0])), unsafe(addr<uint8?>(key_map_north)))
    M_BindVariable(unsafe(addr<int8?>(c2da_str_75[0])), unsafe(addr<uint8?>(key_map_south)))
    M_BindVariable(unsafe(addr<int8?>(c2da_str_76[0])), unsafe(addr<uint8?>(key_map_east)))
    M_BindVariable(unsafe(addr<int8?>(c2da_str_77[0])), unsafe(addr<uint8?>(key_map_west)))
    M_BindVariable(unsafe(addr<int8?>(c2da_str_78[0])), unsafe(addr<uint8?>(key_map_zoomin)))
    M_BindVariable(unsafe(addr<int8?>(c2da_str_79[0])), unsafe(addr<uint8?>(key_map_zoomout)))
    M_BindVariable(unsafe(addr<int8?>(c2da_str_80[0])), unsafe(addr<uint8?>(key_map_toggle)))
    M_BindVariable(unsafe(addr<int8?>(c2da_str_81[0])), unsafe(addr<uint8?>(key_map_maxzoom)))
    M_BindVariable(unsafe(addr<int8?>(c2da_str_82[0])), unsafe(addr<uint8?>(key_map_follow)))
    M_BindVariable(unsafe(addr<int8?>(c2da_str_83[0])), unsafe(addr<uint8?>(key_map_grid)))
    M_BindVariable(unsafe(addr<int8?>(c2da_str_84[0])), unsafe(addr<uint8?>(key_map_mark)))
    M_BindVariable(unsafe(addr<int8?>(c2da_str_85[0])), unsafe(addr<uint8?>(key_map_clearmark)))
    return
}
[export, sideeffects]
def M_BindMenuControls() {
    M_BindVariable(unsafe(addr<int8?>(c2da_str_86[0])), unsafe(addr<uint8?>(key_menu_activate)))
    M_BindVariable(unsafe(addr<int8?>(c2da_str_87[0])), unsafe(addr<uint8?>(key_menu_up)))
    M_BindVariable(unsafe(addr<int8?>(c2da_str_88[0])), unsafe(addr<uint8?>(key_menu_down)))
    M_BindVariable(unsafe(addr<int8?>(c2da_str_89[0])), unsafe(addr<uint8?>(key_menu_left)))
    M_BindVariable(unsafe(addr<int8?>(c2da_str_90[0])), unsafe(addr<uint8?>(key_menu_right)))
    M_BindVariable(unsafe(addr<int8?>(c2da_str_91[0])), unsafe(addr<uint8?>(key_menu_back)))
    M_BindVariable(unsafe(addr<int8?>(c2da_str_92[0])), unsafe(addr<uint8?>(key_menu_forward)))
    M_BindVariable(unsafe(addr<int8?>(c2da_str_93[0])), unsafe(addr<uint8?>(key_menu_confirm)))
    M_BindVariable(unsafe(addr<int8?>(c2da_str_94[0])), unsafe(addr<uint8?>(key_menu_abort)))
    M_BindVariable(unsafe(addr<int8?>(c2da_str_95[0])), unsafe(addr<uint8?>(key_menu_help)))
    M_BindVariable(unsafe(addr<int8?>(c2da_str_96[0])), unsafe(addr<uint8?>(key_menu_save)))
    M_BindVariable(unsafe(addr<int8?>(c2da_str_97[0])), unsafe(addr<uint8?>(key_menu_load)))
    M_BindVariable(unsafe(addr<int8?>(c2da_str_98[0])), unsafe(addr<uint8?>(key_menu_volume)))
    M_BindVariable(unsafe(addr<int8?>(c2da_str_99[0])), unsafe(addr<uint8?>(key_menu_detail)))
    M_BindVariable(unsafe(addr<int8?>(c2da_str_100[0])), unsafe(addr<uint8?>(key_menu_qsave)))
    M_BindVariable(unsafe(addr<int8?>(c2da_str_101[0])), unsafe(addr<uint8?>(key_menu_endgame)))
    M_BindVariable(unsafe(addr<int8?>(c2da_str_102[0])), unsafe(addr<uint8?>(key_menu_messages)))
    M_BindVariable(unsafe(addr<int8?>(c2da_str_103[0])), unsafe(addr<uint8?>(key_menu_qload)))
    M_BindVariable(unsafe(addr<int8?>(c2da_str_104[0])), unsafe(addr<uint8?>(key_menu_quit)))
    M_BindVariable(unsafe(addr<int8?>(c2da_str_105[0])), unsafe(addr<uint8?>(key_menu_gamma)))
    M_BindVariable(unsafe(addr<int8?>(c2da_str_106[0])), unsafe(addr<uint8?>(key_menu_incscreen)))
    M_BindVariable(unsafe(addr<int8?>(c2da_str_107[0])), unsafe(addr<uint8?>(key_menu_decscreen)))
    M_BindVariable(unsafe(addr<int8?>(c2da_str_108[0])), unsafe(addr<uint8?>(key_menu_screenshot)))
    M_BindVariable(unsafe(addr<int8?>(c2da_str_109[0])), unsafe(addr<uint8?>(key_demo_quit)))
    M_BindVariable(unsafe(addr<int8?>(c2da_str_110[0])), unsafe(addr<uint8?>(key_spy)))
    return
}
[export, sideeffects]
def M_BindChatControls(var num_players : uint) {
    var name : int8[32]
    M_BindVariable(unsafe(addr<int8?>(c2da_str_111[0])), unsafe(addr<uint8?>(key_multi_msg)))
    for (i in urange(0u, num_players)) {
        M_snprintf(unsafe(addr<int8?>(name[0])), 32ul, unsafe(addr<int8 const?>(c2da_str_112[0])), [C2daVaArg(tag = 1, i64 = int64(i + 1u), f64 = 0.0lf, raw = 0x0)])
        M_BindVariable(unsafe(addr<int8?>(name[0])), unsafe(addr<uint8?>(unsafe(unsafe(addr(key_multi_msgplayer[0]))[int(i)]))))
    }
    return
}
[export, sideeffects]
def M_ApplyPlatformDefaults() {
    return
}
