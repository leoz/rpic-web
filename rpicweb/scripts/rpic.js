

function rpic_cmd_forward() {
	rpic_set_status("Forward!!!");
    rpic_command("rpic_fwrd");
}

function rpic_cmd_left() {
	rpic_set_status("Left!!!");
    rpic_command("rpic_left");
}

function rpic_cmd_stop() {
	rpic_set_status("Stop!!!");
    rpic_command("rpic_stop");
}

function rpic_cmd_right() {
	rpic_set_status("Right!!!");
    rpic_command("rpic_rght");
}

function rpic_cmd_backward() {
	rpic_set_status("Backward!!!");
    rpic_command("rpic_bkwd");
}

function rpic_cmd_deccelerate() {
	rpic_set_status("Deccelerate!!!");
    rpic_command("rpic_dcl");
}

function rpic_cmd_accelerate() {
	rpic_set_status("Accelerate!!!");
    rpic_command("rpic_acl");
}

function rpic_set_status(text) {
	$("#rpic_footer").text("Status: " + text);
}

// Command
function rpic_command(command) {
    $.get(window.location.protocol+ "//" + window.location.host + "?" + command);
}

