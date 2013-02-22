$(window).load(function(){
	jQuery.fn.center = function() {
		this.css({
			"position": "absolute",
			"top": ((($(window).height() - this.outerHeight()) / 2) + $(window).scrollTop() + "px"),
			"left": ((($(window).width() - this.outerWidth()) / 2) + $(window).scrollLeft() + "px")
		});
	return this;
	}
	$("div.rpi_cam_off").center();
	$(window).bind('resize', function() {
		$('div.rpi_cam_off').center();
	});
});

