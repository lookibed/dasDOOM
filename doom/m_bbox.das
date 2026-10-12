options gen2
options solid_context = true
options stack = 4194304
module m_bbox public

require dasdoom_runtime
[export, sideeffects]
def M_ClearBox(var box : int?) {
    unsafe(box[3]) = -2147483647 - 1
    unsafe(box[0]) = int(unsafe(box[3]))  // nolint:PERF020
    unsafe(box[2]) = 2147483647
    unsafe(box[1]) = int(unsafe(box[2]))  // nolint:PERF020
    return
}
[export, sideeffects]
def M_AddToBox(var box_0 : int?; var x : int; var y : int) {
    if (x < unsafe(box_0[2])) {
        unsafe(box_0[2]) = int(x)  // nolint:PERF020
    } elif (x > unsafe(box_0[3])) {
        unsafe(box_0[3]) = int(x)  // nolint:PERF020
    }
    if (y < unsafe(box_0[1])) {
        unsafe(box_0[1]) = int(y)  // nolint:PERF020
    } elif (y > unsafe(box_0[0])) {
        unsafe(box_0[0]) = int(y)  // nolint:PERF020
    }
    return
}
