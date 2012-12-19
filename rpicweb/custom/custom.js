// Put your custom code here

$(function() {
	$( "#progressbar1" ).progressbar({
		value: 37
	});
	$( "#progressbar2" ).progressbar({
		value: 10
	});
	$( "#progressbar3" ).progressbar({
		value: 85
	});
});

$('#rpic_page_main').live('pageinit', function(event){
        rpic_get_version();
        rpic_poll();
        rpic_show_status("Ready");
        rpic_show_command("Idle");
});

